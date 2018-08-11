#include"paint.h"

color rgb(unsigned char o1, unsigned char o2, unsigned char o3){
    color c;
    c.o1=o1; c.o2=o2; c.o3=o3;
    return c;
}

void save_pixel(pixel px){
    FILE *f=fopen(px.img.path,"rb+");
        fseek(f,from2Dto1D(px),0);
        fwrite(&px.couleur.o3,1,1,f);
        fwrite(&px.couleur.o2,1,1,f);
        fwrite(&px.couleur.o1,1,1,f);
    fclose(f);
}

unsigned int from2Dto1D(pixel px){
    px.y=px.img.h-px.y;
    return EN_TETE_SIZE+3*((px.y-1)*(px.img.l+1)+px.x);
}