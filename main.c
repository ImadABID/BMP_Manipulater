#include "src/paint.h"

int main(){

    image img=set_image("6px.bmp",3,2);
    set_header_image(img);

        color bleu; bleu.o1=0; bleu.o2=0; bleu.o3=255;
        color red; red.o1=255; red.o2=0; red.o3=0; 

        pixel px1;
        px1.img=img;
        px1.x=0;
        px1.y=0;
        px1.couleur= red;

        pixel px2;
        px2.img=img;
        px2.x=1;
        px2.y=0;
        px2.couleur= bleu;

        pixel px3;
        px3.img=img;
        px3.x=2;
        px3.y=0;
        px3.couleur= bleu;

        pixel px4;
        px4.img=img;
        px4.x=0;
        px4.y=1;
        px4.couleur= bleu;

        pixel px5;
        px5.img=img;
        px5.x=1;
        px5.y=1;
        px5.couleur= bleu;

        pixel px6;
        px6.img=img;
        px6.x=2;
        px6.y=1;
        px6.couleur= bleu;

        save_pixel(px1);
        save_pixel(px2);
        save_pixel(px3);
        save_pixel(px4);
        save_pixel(px5);
        save_pixel(px6);

        
    set_footer_image(img);


    return 0;
}

