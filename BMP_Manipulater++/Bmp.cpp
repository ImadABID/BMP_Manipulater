#include "Bmp.hpp"
Bmp::Bmp(char *img_path, int lenght, int hight){
	this::path=malloc(255); this::path=img_path;


    if(lenght==-1 && hight==-1){ //image existe
        FILE *f=fopen(this::path,"rb");
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

        this::l=pl;
        this::h=ph;
        this::size=ps;
        fread(this::hex,this::size,1,f);
        fclose(f);
    }else{ //create a new image
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
            //Error: size is too big
        }
        this::hex=malloc(this::size);
        FILE *fichier=fopen(this::path,"r");
            this::set_header_image();
        fclose(fichier);
    }

};

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
};

unsigned char *Bmp::adapt(unsigned char *p){
    const char taille=4;
    unsigned char *q=malloc(taille);
    int i;
    for(i=0;i<taille;i++){
        q[i]=p[taille-1-i];
    }
    return q;
};

color Bmp::rgb(unsigned char o1, unsigned char o2, unsigned char o3){
    color c;
    c.o1=o1; c.o2=o2; c.o3=o3;
    return c;
};
pixel Bmp::get_pixel(int x, int y){
    pixel px; px.x=x; px.y=y; px.couleur = this::rgb(0,0,0);
    int offset=from2Dto1D(px);
    color c;
        c.o3=this::hex[offset];
        c.o2=this::hex[offset+1];
        c.o1=this::hex[offset+2];
    
    px.couleur=c;

    return px;
}