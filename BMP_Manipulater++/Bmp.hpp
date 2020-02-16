#if !defined(__BMP__)
#define __BMP__

#include<string>
#include <memory>
#include"Binnary.hpp"
#define EN_TETE_SIZE 54
#define RAM_MAX 26214400 // 25Mo

struct color{
    unsigned char o1;
    unsigned char o2;
    unsigned char o3;
};

struct pixel{
    int x;
    int y;
    color couleur;
};

class Bmp{
public:
	Bmp(std::string img_path, int lenght, int hight);//level:2
	pixel get_pixel(int x, int y); //level:1
	void put_pixel(pixel px); //level:1
	void save(); //level:0
private:
	std::string path;
    int l;
    int h;
    int add;
    int size;
    unsigned char *hex;

    void set_header_image();//level:1
    unsigned char *adapt(unsigned char *p);//level:0
    color rgb(unsigned char o1, unsigned char o2, unsigned char o3);//level:0
    unsigned int from2Dto1D(pixel px);//level:0
};
#endif