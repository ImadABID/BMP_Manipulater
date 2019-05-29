#include "Bmp.hpp"
int main(){
	Bmp img=Bmp("test.bmp",-1,-1);
	img.save();
	return 0;
}