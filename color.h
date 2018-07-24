#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    false,true
}bool;

typedef struct structure{
    char o1;
    char o2;
    char o3;
}color;

typedef struct structure2{
    int l;
    int h;
    char *path;
}image;


void set_header_image(image img);
void set_footer_image(image img);
void inverse(image img);
color rgb(char o1, char o2, char o3);

bool is_gray_background();
#endif
//int fseek ( FILE * stream, long int current, int final ); SEEK_END