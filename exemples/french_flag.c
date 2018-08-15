#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"
#define L 241
#define H 120
int main(){

    image img=set_image("french_flag.bmp",L,H);
    set_header_image(img);

    color red=rgb(255,0,0);
    color white=rgb(255,255,255);
    color bleu=rgb(0,0,255); 

    pixel px; px.img= img;
    int x,y;

    px.couleur=red;
    for(x=0;x<L/3;x++){
        px.x=x;
        for(y=0;y<H;y++){
            px.y=y;
            save_pixel(px);
        }
    }

    px.couleur=white;
    for(x=L/3;x<2*L/3;x++){
        px.x=x;
        for(y=0;y<H;y++){
            px.y=y;
            save_pixel(px);
        }
    }

    px.couleur=bleu;
    for(x=2*L/3;x<L;x++){
        px.x=x;
        for(y=0;y<H;y++){
            px.y=y;
            save_pixel(px);
        }
    }


    return 0;
}

