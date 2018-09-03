#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"
#include <stdio.h>

#define L 100
#define H 30
#define L_PX 4
#define H_PX 8
#define TRAIT_PX 1

int main(){

    int img_l =L*L_PX+TRAIT_PX*(L+1);
    int img_h =H*H_PX+TRAIT_PX*(H+1);

    image img=set_image("grille.bmp",img_l,img_h);
    pixel px; px.img=img;
    px.couleur=rgb(255,255,255);

    //image blanche
    for(int i=0;i<img_l;i++){
        px.x=i;
        for(int j=0;j<img_h;j++){
            px.y=j;
            put_pixel(px);
        }
    }

    px.couleur=rgb(0,0,0);

    //grille verticale
    for(int i=0;i<img_l;i+=L_PX){
        px.x=i;
        for(int j=0;j<img_h;j++){
            px.y=j;
            put_pixel(px);
        }
    }

    //grille horizontale
    for(int j=0;j<img_h;j+=H_PX){
        px.y=j;
        for(int i=0;i<img_l;i++){
            px.x=i;
            put_pixel(px);
        }
    }

    save_image(img);

    return 0;
}