#include "Bmp.hpp"
Bmp::Bmp(char *img_path, int lenght, int hight){
	this::path=malloc(255); this::path=img_path;
    this::l= lenght;
    this::h= hight;

    /*to 4*k */{
        int l=3*this::l;
        this::add=0;
        double k = (double) l/4;
        while( (int)k != k){
            this::add++;
            k = ((double)(l+this::add)/4);
        }
    }

    this::size=EN_TETE_SIZE+3*lenght*hight+this::add*hight;

    if(img.size>RAM_MAX){
        //Error
    }

    this::hex=malloc(this::size);

    FILE *fichier=fopen(this::path,"r");
        if(fichier==NULL) this::set_header_image();
        else fread(this::hex,this::size,1,fichier);
    fclose(fichier);
}

Bmp Bmp::open(char *path){
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

void Bmp::set_header_image(){
	unsigned char p2oct[2]={66,77};

        this::hex[0]=66; this::hex[1]=77; //signature bmp

        unsigned char *p4oct=malloc(4);
        p4oct=adapt(DtoH(img.size));
        this::hex[2]=p4oct[0]; this::hex[3]=p4oct[1];
        this::hex[4]=p4oct[2]; this::hex[5]=p4oct[3];//size of file

        this::hex[6]=0; this::hex[7]=0;
        this::hex[8]=0; this::hex[9]=0;

        this::hex[10]=54; this::hex[11]=0;
        this::hex[12]=0; this::hex[13]=0;

        this::hex[14]=40; this::hex[15]=0;
        this::hex[16]=0; this::hex[17]=0;

        p4oct=adapt(DtoH(img.l));
        this::hex[18]=p4oct[0]; this::hex[19]=p4oct[1];
        this::hex[20]=p4oct[2]; this::hex[21]=p4oct[3];//lenght

        p4oct=adapt(DtoH(img.h));
        this::hex[22]=p4oct[0]; this::hex[23]=p4oct[1];
        this::hex[24]=p4oct[2]; this::hex[25]=p4oct[3];//hight

        this::hex[26]=1; this::hex[27]=0;
        this::hex[28]=24; this::hex[29]=0;

        this::hex[30]=0; this::hex[31]=0;
        this::hex[32]=0; this::hex[33]=0;

        this::hex[34]=24; this::hex[35]=0;

        int i;
        for(i=0;i<18;i++){
            this::hex[36+i]=0;
        }

        //Inisialize the body of the image to 00
        for(i=0;i<this::size-EN_TETE_SIZE;i++){
            this::hex[EN_TETE_SIZE+i]=0;
        }
}

unsigned char *Bmp::adapt(unsigned char *p){
    const char taille=4;
    unsigned char *q=malloc(taille);
    int i;
    for(i=0;i<taille;i++){
        q[i]=p[taille-1-i];
    }
    return q;
}