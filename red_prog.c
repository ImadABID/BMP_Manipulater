#include "src/paint.h"
#define L 6
#define H 4

int main(){
    image img=set_image("red_prog.bmp",L,H);
    set_header_image(img);
    

    pixel px; px.img=img; px.couleur=rgb(255,0,0);

    int i,j;
    for(i=0;i<L;i++){
        px.x=i;
        for(j=0;j<H;j++){
            px.y=j;
            save_pixel(px);
        }
    }

    return 0;
}