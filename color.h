#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *fic;

typedef enum {
    false,true
}bool;

typedef struct structure{
    char o1;
    char o2;
    char o3;
}color;

void set_header_image( int l, int h);
void set_footer_image(int l, int h);
color rgb(char o1, char o2, char o3);

bool is_gray_background(color c);
#endif