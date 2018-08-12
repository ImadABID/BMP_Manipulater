#include "src/paint.h"
#include <stdio.h>

int main(){
    image img=open("red.bmp");

    printf("\npath:%s",img.path);
    printf("\nsize:%d",img.size);
    printf("\npath:%d",img.l);
    printf("\npath:%d",img.h);
    

    pixel px; px.img=img; px.couleur=rgb(0,128,0); px.x=2; px.y=2;
    save_pixel(px);

    px.x=3; px.y=1;
    save_pixel(px);
    return 0;
}