#include"paint.h"

color rgb(unsigned char o1, unsigned char o2, unsigned char o3){
    color c;
    c.o1=o3; c.o2=o2; c.o3=o1;
    return c;
}

void save_pixel(pixel px){

}

unsigned int from2Dto1D(pexel px){
    px.y=image.h-px.y;
    return (54+(px.y-1)*px.image.l+px.x);
} 