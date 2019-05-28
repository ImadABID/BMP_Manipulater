#include "Binnary.hpp"

unsigned int Binnary::HtoD(unsigned char *p){
	return p[0]*_256P3+p[1]*_256P2+p[2]*256+p[3];
};

unsigned char *Binnary::DtoH(unsigned int e){
	unsigned char *p=malloc(4);
    p[0]=(int)(e/_256P3);
    e-=p[3]*_256P3;

    p[1]=(int)(e/_256P2);
    e-=p[2]*_256P2;

    p[2]=(int)(e/256);
    e-=p[1]*256;

    p[3]=e;
    return p;
};