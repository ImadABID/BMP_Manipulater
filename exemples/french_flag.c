#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"

int main(){

    image img=set_image("french_flag.bmp",256,128);

    color red=rgb(255,0,0);
    color white=rgb(255,255,255);
    color bleu=rgb(0,0,255); 

    pixel px; px.img= img;
    int x,y;

    px.couleur=red;
    for(x=0;x<img.l/3;x++){
        px.x=x;
        for(y=0;y<img.h;y++){
            px.y=y;
            put_pixel(px);
        }
    }

    px.couleur=white;
    for(x=img.l/3;x<2*img.l/3;x++){
        px.x=x;
        for(y=0;y<img.h;y++){
            px.y=y;
            put_pixel(px);
        }
    }

    px.couleur=bleu;
    for(x=2*img.l/3;x<img.l;x++){
        px.x=x;
        for(y=0;y<img.h;y++){
            px.y=y;
            put_pixel(px);
        }
    }

    save_image(img);

    return 0;
}