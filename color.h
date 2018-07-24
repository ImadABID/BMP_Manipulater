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



void set_header_image();
void set_footer_image();
void inverse();
color rgb(char o1, char o2, char o3);

bool is_gray_background();
#endif
//int fseek ( FILE * stream, long int current, int final ); SEEK_END