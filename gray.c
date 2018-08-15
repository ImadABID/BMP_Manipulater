#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"
#include <stdio.h>

int main(){

    image img=set_image("gray.bmp",23,12);set_header_image(img);
    printf("\nl=%d\n",img.l);
    printf("h=%d\n",img.h);
    printf("add=%d\n",img.add);
    printf("size=%d\n",img.size);

    color gray=rgb(255,255,255);

    pixel px; px.img= img; px.couleur=gray;
    
    for(int x=0; x<img.l; x++){
        px.x=x;
        for(int y=0; y<img.h; y++){
            printf("\nM(%d,%d)",x,y);
            px.x=x;
            save_pixel(px);
        }
    }


    return 0;
}