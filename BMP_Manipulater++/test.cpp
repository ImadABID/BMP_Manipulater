//#include "Bmp.hpp"
#include <iostream>
#include <memory>

#include"Binnary.hpp"

int main(){
	Bmp img{"test.bmp",10,10};
	pixel px;
	color c;
	c.o1=232;
	c.o3=24;
	c.o2=125;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			px.x=i;
			px.y=j;
			px.couleur=c;
			img.put_pixel(px);
		}
	}
	img.save();
	return 0;
}