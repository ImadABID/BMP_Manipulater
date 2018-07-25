#include "color.h"

image set_image(char *img_path, int lenght, hight){
    image img
    img.path=img_path;
    img.l= lenght;
    img.h= hight;
    return img;
}

image open(char *path){
    int l,h;
    FILE *f=fopen(path,"rb");
        fseek(f,19,SEEK_SET);
        unsigned char pl[2];
        fread(pl,1,2,f);
        {unsigned char tmp=pl[0]; pl[0]=pl[1]; pl[1]=tmp;}

        fseek(f,23,SEEK_SET);
        unsigned char ph[2];
        fread(ph,1,2,f);
        {unsigned char tmp=ph[0]; ph[0]=ph[1]; ph[1]=tmp;}
    fclose(f);
    return set_image(path,HtoD(pl),HtoD(ph));
}

void set_header_image(image img){

}

void set_footer_image(image img){

}

color rgb(unsigned char o1, unsigned char o2, unsigned char o3){
    color c;
    c.o1=o3; c.o2=o2; c.o3=o1;
    return c;
}

void inverse(image img){
    FILE *f=fopen(img.path,"rb");
        int size=sizeof_image(img);
        unsigned char *p=malloc(size);

        int i;
        for(i=0;i<size;i++){
            fread=(&p[size-i],1,1,f);
        }
    fclose(f);

    FILE *fn=fopen(img.path,"wb");
        fwrite(p,1,size,fn);
    fclose(fn);
}

int sizeof_image(image img){
    unsigned char p[4];
    FILE *f=fopen(img.path,"rb");
        fseek(f,3,SEEK_SET);
        fread(p,1,4,f);
    fclose(f); 
    int r=HtoD(adapt(p));
    return r;
}


bool is_gray_background(pixel px){

    return false;
}