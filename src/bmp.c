#include "bmp.h"

image set_image(char *img_path, int lenght, int hight){
    image img;
    img.path=malloc(255); img.path=img_path;
    img.l= lenght;
    img.h= hight;

    /*to 4*k */{
        int l=3*img.l;
        img.add=0;
        double k = (double) l/4;
        printf("%lf",k);
        while( (int)k != k){
            img.add++;
            k = (l+img.add)/4;
            printf("+1");
        }
    }

    img.size=EN_TETE_SIZE+3*lenght*hight+img.add*hight;

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
    FILE *f=fopen(img.path,"wb");
        fwrite(p2oct,1,2,f); //signature bmp

        fwrite(adapt(DtoH(img.size)),1,4,f); //size of file

        p2oct[0]=0; p2oct[1]=0;
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);

        p2oct[0]=54;
        fwrite(p2oct,1,2,f);
        p2oct[0]=0;
        fwrite(p2oct,1,2,f);

        p2oct[0]=40;
        fwrite(p2oct,1,2,f);
        p2oct[0]=0;
        fwrite(p2oct,1,2,f);

        fwrite(adapt(DtoH(img.l)),1,4,f); //lenght
        fwrite(adapt(DtoH(img.h)),1,4,f); //hight

        p2oct[0]=1;
        fwrite(p2oct,1,2,f);
        p2oct[0]=24; 
        fwrite(p2oct,1,2,f);

        p2oct[0]=0; 
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);

        p2oct[0]=24; 
        fwrite(p2oct,1,2,f);

        int i;
        for(i=0;i<18;i++){
            fwrite(&p2oct[1],1,1,f);
        }

        //Inisialize the body of the image to 00
        for(i=0;i<img.size-EN_TETE_SIZE;i++){
            fwrite(&p2oct[1],1,1,f);
        }

    fclose(f);
}

unsigned char *adapt(unsigned char *p){
    const char taille=4;
    unsigned char *q=malloc(taille);
    int i;
    for(i=0;i<taille;i++){
        q[i]=p[taille-1-i];
    }
    return q;
}