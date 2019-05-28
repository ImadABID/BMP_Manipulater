#if !defined(__BMP__)
#define __BMP__

#include"Binnary.hpp"
#define EN_TETE_SIZE 54
#define RAM_MAX 26214400 // 25Mo

typedef struct structure_of_pixel{
	Bmp img;
    int x;
    int y;
    color couleur;
}pixel;

typedef struct structure_of_color{
    unsigned char o1;
    unsigned char o2;
    unsigned char o3;
}color;



class Bmp{
public:
	Bmp(char *img_path, int lenght, int hight);
	pixel get_pixel(int x, int y);
	void put_pixel(pixel px);
	void save();
private:
	char *path;
    int l;
    int h;
    int add;
    int size;
    unsigned char *hex;

    void Bmp::set_header_image();
    unsigned char *Bmp::adapt(unsigned char *p);
    color rgb(unsigned char o1, unsigned char o2, unsigned char o3);
    unsigned int from2Dto1D(pixel px);
};
#endif