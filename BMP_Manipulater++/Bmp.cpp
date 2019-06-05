#include "Bmp.hpp"
Bmp::Bmp(std::string img_path, int lenght, int hight){
	path=img_path;

    if(lenght==-1 && hight==-1){ //image existe
        FILE *f=fopen(path,"rb");
        //size
        std::unique_ptr<unsigned char[]> ps{std::make_unique<unsigned char>(4)};
        fseek(f,2,SEEK_SET);
        fread(ps,1,4,f);
        ps=adapt(std::move(ps));

        //Length
        fseek(f,18,SEEK_SET);
        std::unique_ptr<unsigned char[]> pl{std::make_unique<unsigned char>(4)};
        fread(pl,1,4,f);
        pl=adapt(std::move(pl));

        //Hight
        fseek(f,22,SEEK_SET);
        std::unique_ptr<unsigned char[]> ph{std::make_unique<unsigned char>(4)};

        fread(ph,1,4,f);
        ph=adapt(std::move(ph));

        l=pl;
        h=ph;
        size=ps;
        hex{std::make_unique<unsigned char[]>(size)};
        fread(hex,size,1,f);
        fclose(f);
    }else{ //create a new image
        l= lenght;
        h= hight;
        
        /*to 4*k */{
            int l=3*l;
            add=0;
            double k = (double) l/4;
            while( (int)k != k){
                add++;
                k = ((double)(l+add)/4);
            }
        }
        
        size=EN_TETE_SIZE+3*lenght*hight+add*hight;

        if(img.size>RAM_MAX){
            //Error: size is too big
        }
        hex{std::make_unique<unsigned char[]>(size)};
        FILE *fichier=fopen(path,"r");
            set_header_image();
        fclose(fichier);
    }

};

void Bmp::set_header_image(){
	unsigned char p2oct[2]={66,77};

        hex[0]=66; hex[1]=77; //signature bmp

        std::unique_ptr<unsigned char[]> p4oct{std::make_unique<unsigned char>(4)};
        p4oct=adapt(std::move(Binnary::DtoH(size)));
        hex[2]=p4oct[0]; hex[3]=p4oct[1];
        hex[4]=p4oct[2]; hex[5]=p4oct[3];//size of file

        hex[6]=0; hex[7]=0;
        hex[8]=0; hex[9]=0;

        hex[10]=54; hex[11]=0;
        hex[12]=0; hex[13]=0;

        hex[14]=40; hex[15]=0;
        hex[16]=0; hex[17]=0;

        p4oct=adapt(std::move(Binnary::DtoH(img.l)));
        hex[18]=p4oct[0]; hex[19]=p4oct[1];
        hex[20]=p4oct[2]; hex[21]=p4oct[3];//lenght

        p4oct=adapt(Binnary::DtoH(img.h));
        hex[22]=p4oct[0]; hex[23]=p4oct[1];
        hex[24]=p4oct[2]; hex[25]=p4oct[3];//hight

        hex[26]=1; hex[27]=0;
        hex[28]=24; hex[29]=0;

        hex[30]=0; hex[31]=0;
        hex[32]=0; hex[33]=0;

        hex[34]=24; hex[35]=0;

        int i;
        for(i=0;i<18;i++){
            hex[36+i]=0;
        }

        //Inisialize the body of the image to 00
        for(i=0;i<size-EN_TETE_SIZE;i++){
            hex[EN_TETE_SIZE+i]=0;
        }
};

std::unique_ptr<unsigned char[]> Bmp::adapt(unsigned char *p){
    const char taille=4;
    std::unique_ptr<unsigned char[]> q{std::make_unique<unsigned char>(taille)};
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
    pixel px;
    px.x=x; px.y=y; px.couleur = rgb(0,0,0);
    int offset=from2Dto1D(px);
    color c;
        c.o3=hex[offset];
        c.o2=hex[offset+1];
        c.o1=hex[offset+2];
    
    px.couleur=c;

    return px;
};

void Bmp::put_pixel(pixel px){
        hex[from2Dto1D(px)]=px.couleur.o3;
        hex[from2Dto1D(px)+1]=px.couleur.o2;
        hex[from2Dto1D(px)+2]=px.couleur.o1;
};

void Bmp::save(){
    FILE *f=fopen(path,"wb");
        fwrite(hex,size,1,f);
    fclose(f);
};

unsigned int Bmp::from2Dto1D(pixel px){
    px.y=h-px.y-1;
    return EN_TETE_SIZE+3*(px.y*l+px.x)+add*px.y;
};