#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>
#include <stdlib.h>
#include "binaire.h"

typedef enum {
    false,true
}bool;

typedef struct structure{
    unsigned char o1;
    unsigned char o2;
    unsigned char o3;
}color;

typedef struct structure2{
    char *path;
    int l;
    int h;
}image;

typedef struct structure2{
    image img;
    int x;
    int y;
    color couleur;
}pixel;

image set_image(char *img_path, int lenght, hight);
void set_header_image(image img);
void set_footer_image(image img);
int sizeof_image(image img);

unsigned char *adapt(unsigned char *p);
void inverse(image img);

color rgb(unsigned char o1, unsigned char o2, unsigned char o3);

bool is_gray_background(pixel px);
#endif
//int fseek ( FILE * stream, long int current, int final ); SEEK_END