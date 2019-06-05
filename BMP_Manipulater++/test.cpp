//#include "Bmp.hpp"
#include <iostream>
#include<memory>

#define _256P3 16777216
#define _256P2 65536

class Binnary{
public:
	static unsigned int HtoD(std::unique_ptr<unsigned char[]> p);
};

unsigned int Binnary::HtoD(std::unique_ptr<unsigned char[]> p){
	return p[0]*_256P3+p[1]*_256P2+p[2]*256+p[3];
};

int main(){
//	Bmp img{"test.bmp",-1,-1};
//	img.save();
//	std::cout<<Binnary::HtoD(Binnary::DtoH(100))<<std::endl;
	
	std::unique_ptr<unsigned char[]> p{std::make_unique<unsigned char[]>(4)};
	p[0]=200;p[1]=200;p[2]=200;p[3]=200;
	std::cout<<p[0]<<std::endl;
	std::cout<<p[1]<<std::endl;
	std::cout<<p[2]<<std::endl;
	std::cout<<p[3]<<std::endl;

	std::cout<<Binnary::HtoD(std::move(p))<<std::endl;

	return 0;
}