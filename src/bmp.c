#include "bmp.h"

/*-----------------------Image parameters--------------------------------------*/
image set_image(char *img_path, int lenght, int hight){
    image img;
    img.path=malloc(255); img.path=img_path;
    img.l= lenght;
    img.h= hight;

    /*to 4*k */{
        int l=3*img.l;
        img.add=0;
        double k = (double) l/4;
        while( (int)k != k){
            img.add++;
            k = ((double)(l+img.add)/4);
        }
    }

    img.size=EN_TETE_SIZE+3*lenght*hight+img.add*hight;

    if(img.size>RAM_MAX) return NULL;

    img.hex=malloc(img.size);

    FILE *fichier=fopen(img.path,"r");
    if(fichier==NULL) set_header_image(img);
    else fread(img.hex,img.size,1,fichier);
    fclose(fichier);

    return img;
}

image open(char *path){
    FILE *f=fopen(path,"rb");
        //size
        unsigned char *ps=malloc(4);
        fseek(f,2,SEEK_SET);
        fread(ps,1,4,f);
        ps=adapt(ps);

        //Length
        fseek(f,18,SEEK_SET);
        unsigned char *pl=malloc(4);
        fread(pl,1,4,f);
        pl=adapt(pl);

        //Hight
        fseek(f,22,SEEK_SET);
        unsigned char *ph=malloc(4);
        fread(ph,1,4,f);
        ph=adapt(ph);
    fclose(f);

    return set_image(path, HtoD(pl), HtoD(ph));
}

void set_header_image(image img){
    unsigned char p2oct[2]={66,77};

        img.hex[0]=66; img.hex[1]=77; //signature bmp

        unsigned char *p4oct=malloc(4);
        p4oct=adapt(DtoH(img.size));
        img.hex[2]=p4oct[0]; img.hex[3]=p4oct[1];
        img.hex[4]=p4oct[2]; img.hex[5]=p4oct[3];//size of file

        img.hex[6]=0; img.hex[7]=0;
        img.hex[8]=0; img.hex[9]=0;

        img.hex[10]=54; img.hex[11]=0;
        img.hex[12]=0; img.hex[13]=0;

        img.hex[14]=40; img.hex[15]=0;
        img.hex[16]=0; img.hex[17]=0;

        p4oct=adapt(DtoH(img.l));
        img.hex[18]=p4oct[0]; img.hex[19]=p4oct[1];
        img.hex[20]=p4oct[2]; img.hex[21]=p4oct[3];//lenght

        p4oct=adapt(DtoH(img.h));
        img.hex[22]=p4oct[0]; img.hex[23]=p4oct[1];
        img.hex[24]=p4oct[2]; img.hex[25]=p4oct[3];//hight

        img.hex[26]=1; img.hex[27]=0;
        img.hex[28]=24; img.hex[29]=0;

        img.hex[30]=0; img.hex[31]=0;
        img.hex[32]=0; img.hex[33]=0;

        img.hex[34]=24; img.hex[35]=0;

        int i;
        for(i=0;i<18;i++){
            img.hex[36+i]=0;
        }

        //Inisialize the body of the image to 00
        for(i=0;i<img.size-EN_TETE_SIZE;i++){
            img.hex[EN_TETE_SIZE+i]=0;
        }

}

/*-----------------------Image Elements--------------------------------------*/
color rgb(unsigned char o1, unsigned char o2, unsigned char o3){
    color c;
    c.o1=o1; c.o2=o2; c.o3=o3;
    return c;
}

void put_pixel(pixel px){
        px.img.hex[from2Dto1D(px)]=px.couleur.o3;
        px.img.hex[from2Dto1D(px)+1]=px.couleur.o2;
        px.img.hex[from2Dto1D(px)+2]=px.couleur.o1;
}

/*-------------------------Save data----------------------------*/
void save_pixel(unsigned char *hex){
    FILE *f=fopen(px.img.path,"rb+");
        fwrite(hex,px.img.size,1,f);
    fclose(f);
}

/*---------------------Adapting for bmp--------------------------------*/
unsigned char *adapt(unsigned char *p){
    const char taille=4;
    unsigned char *q=malloc(taille);
    int i;
    for(i=0;i<taille;i++){
        q[i]=p[taille-1-i];
    }
    return q;
}

unsigned int from2Dto1D(pixel px){
    px.y=px.img.h-px.y-1;
    return EN_TETE_SIZE+3*(px.y*px.img.l+px.x)+px.img.add*px.y;
}