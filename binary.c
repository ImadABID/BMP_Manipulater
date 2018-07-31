#include "binary.h"
#define _256P3 16777216
#define _256P2 65536
unsigned int HtoD(unsigned char *p){
    return p[0]*_256P3+p[1]*_256P2+p[2]*256+p[3];
}

unsigned char *DtoH(unsigned int *e){
    unsigned char *p=malloc(4);
    p[3]=(int)(e/_256P3);
    int e-=p[3]*_256P3;

    p[2]=(int)(e/_256P2);
    int e-=p[2]*_256P2;

    p[1]=(int)(e/256);
    int e-=p[1]*256;

    p[0]=e;
    return p;
}