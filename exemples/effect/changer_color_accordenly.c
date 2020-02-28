#include <stdio.h>
#include "bmp.h"

unsigned char boule_255(int x);
color add_vector_color(color c1, int *vecteur_color);
int main(){
    image img=open("img.bmp");
    int *vecteur_color=malloc(12);

    vecteur_color[0]=242-34;
    vecteur_color[1]=121-43;
    vecteur_color[2]=57-246;

    int i,j;
    pixel px;
    for(i=0;i<img.l;i++){
        for(j=0;j<img.h;j++){
            px=get_pixel(img,i,j);
            px.couleur=add_vector_color(px.couleur, vecteur_color);
            put_pixel(px);
        }
    }
    save_image(img);
    return 0;
}
color add_vector_color(color c1, int *vecteur_color){
    int x1,x2,x3;
    x1=(int) c1.o1; x2=(int) c1.o2; x3=(int) c1.o3;
    
    c1.o1 = boule_255(x1+vecteur_color[0]);
    c1.o2 = boule_255(x2+vecteur_color[1]);
    c1.o3 = boule_255(x3+vecteur_color[2]);
    return c1;
}
/*
color add_vector_color(color c1, int *vecteur_color){
    
    c1.o1 = boule_255(x2+vecteur_color[1]);
    c1.o1 = boule_255(x3+vecteur_color[2]);
    return c1;
}*/


unsigned char boule_255(int x){
    if(x>255)
        return (unsigned char) (2*255-x);
    if(x<0)
        return (unsigned char) -x;
    return (unsigned char) x;
}