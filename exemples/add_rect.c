#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"

int main(){
    image img=open("french_flag.bmp");

    pixel px; px.img= img; px.couleur=rgb(128,255,128);

    int x,y;
    for(x=(int)(img.l/3);x<(int)(img.l*2/3);x++){
        px.x=x;
        for(y=(int)(img.h/3);y<(int)(img.h*2/3);y++){
            px.y=y;
            save_pixel(px);
        }
    }

    return 0;
}