#include "src/paint.h"
#define L 255
#define H 128
int main(){

    image img=set_image("french_flag.bmp",L,H);
    set_header_image(img);

    color red=rgb(255,0,0);
    color white=rgb(255,255,255);
    color bleu=rgb(0,0,255); 

    pixel px; px.img= img;
    int x,y;

    px.couleur=red;
    for(x=0;x<85;x++){
        px.x=x;
        for(y=0;y<H;y++){
            px.y=y;
            save_pixel(px);
        }
    }

    px.couleur=white;
    for(x=85;x<2*85;x++){
        px.x=x;
        for(y=0;y<H;y++){
            px.y=y;
            save_pixel(px);
        }
    }

    px.couleur=bleu;
    for(x=2*85;x<3*85;x++){
        px.x=x;
        for(y=0;y<H;y++){
            px.y=y;
            save_pixel(px);
        }
    }


    return 0;
}

