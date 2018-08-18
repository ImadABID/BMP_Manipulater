#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"
#include <stdio.h>

int main(){
    printf("Opening image ...\n");
    image img=open("image.bmp");

    printf("treating image ...\n");
    pixel px; px.img= img; px.couleur=rgb(200,255,200);

    int x,y;
    for(x=(int)(img.l/3);x<(int)(img.l*2/3);x++){
        px.x=x;
        for(y=(int)(img.h/3);y<(int)(img.h*2/3);y++){
            px.y=y;
            put_pixel(px);
        }
    }

    printf("saving image ...");
    save_image(img);

    return 0;
}