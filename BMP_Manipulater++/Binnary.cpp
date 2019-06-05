#include "Binnary.hpp"

unsigned int Binnary::HtoD(std::unique_ptr<unsigned char[]> p){
	return p[0]*_256P3+p[1]*_256P2+p[2]*256+p[3];
};
/*
std::unique_ptr<unsigned char[]> Binnary::DtoH(unsigned int e){
	std::unique_ptr<unsigned char[]> p{std::make_unique<unsigned char>(4)};
    p[0]=(int)(e/_256P3);
    e-=p[3]*_256P3;

    p[1]=(int)(e/_256P2);
    e-=p[2]*_256P2;

    p[2]=(int)(e/256);
    e-=p[1]*256;

    p[3]=e;
    return p;
};
*/