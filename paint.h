#ifndef __PAINT_H__
#define __PAINT_H__

#include "bmp.h"

typedef struct structure3{
    image img;
    int x;
    int y;
    color couleur;
}pixel;

typedef struct structure{
    unsigned char o1;
    unsigned char o2;
    unsigned char o3;
}color;

color rgb(unsigned char o1, unsigned char o2, unsigned char o3);

#endif