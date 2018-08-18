#ifndef __BMP_H__
#define __BMP_H__

#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

#define EN_TETE_SIZE 54
#define RAM_MAX 26214400 // 25Mo

/*------------------------Structures----------------*/
typedef enum {
    false,true
}bool;

typedef struct structure2{
    char *path;
    int l;
    int h;
    int add;
    int size;
    unsigned char *hex;
}image;

typedef struct structure_of_color{
    unsigned char o1;
    unsigned char o2;
    unsigned char o3;
}color;

typedef struct structure_of_pixel{
    image img;
    int x;
    int y;
    color couleur;
}pixel;

/*---------------Functions-------------------*/

image set_image(char *img_path, int lenght, int hight);
image open(char *path);
void set_header_image(image img);

color rgb(unsigned char o1, unsigned char o2, unsigned char o3);
void put_pixel(pixel px);

void save_image(image img);

unsigned char *adapt(unsigned char *p);
unsigned int from2Dto1D(pixel px);

#endif
