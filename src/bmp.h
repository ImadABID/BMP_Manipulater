#ifndef __BMP_H__
#define __BMP_H__

#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

#define EN_TETE_SIZE 54

typedef enum {
    false,true
}bool;

typedef struct structure2{
    char *path;
    int size;
    int l;
    int h;
}image;

image set_image(char *img_path, int lenght, int hight);

image open(char *path);

void set_header_image(image img);

unsigned char *adapt(unsigned char *p);

#endif
