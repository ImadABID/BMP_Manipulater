#if !defined(__BMP__)
#define __BMP__

#include<memory>
#include<string>
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
	Bmp(std::string img_path, int lenght, int hight);
	pixel get_pixel(int x, int y);
	void put_pixel(pixel px);
	void save();
private:
	std::string path;
    int l;
    int h;
    int add;
    int size;
    std::unique_ptr hex{nullptr};

    void set_header_image();
    unsigned char *adapt(unsigned char *p);
    color rgb(unsigned char o1, unsigned char o2, unsigned char o3);
    unsigned int from2Dto1D(pixel px);
};
#endif