#include "bmp.h"
#include <stdio.h>

#define L 3
#define H 2
#define L_PX 50
#define H_PX 50

int main(){

    int img_l =L*L_PX+1;
    int img_h =H*H_PX+1;

    image img=set_image("grille.bmp",img_l,img_h);
    pixel px; px.img=img;
    px.couleur=rgb(255,255,255);

    int i,j;
    //image blanche
    for(i=0;i<img_l;i++){
        px.x=i;
        for(j=0;j<img_h;j++){
            px.y=j;
            put_pixel(px);
        }
    }

    px.couleur=rgb(0,0,0);

    //grille verticale
    for(i=0;i<img_l;i+=L_PX){
        px.x=i;
        for(j=0;j<img_h;j++){
            px.y=j;
            put_pixel(px);
        }
    }

    //grille horizontale
    for(j=0;j<img_h;j+=H_PX){
        px.y=j;
        for(i=0;i<img_l;i++){
            px.x=i;
            put_pixel(px);
        }
    }

    save_image(img);

    return 0;
}