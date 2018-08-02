#ifndef __PAINT_H__
#define __PAINT_H__

#include "bmp.h"

typedef struct structure{
    unsigned char o1;
    unsigned char o2;
    unsigned char o3;
}color;

typedef struct structure3{
    image img;
    int x;
    int y;
    color couleur;
}pixel;

color rgb(unsigned char o1, unsigned char o2, unsigned char o3);

unsigned int from2Dto1D(pixel px);

#endif