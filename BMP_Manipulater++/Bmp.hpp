#if ! defined(__BMP__)
#define(__BMP__)

#define EN_TETE_SIZE 54
#define RAM_MAX 26214400 // 25Mo

class Bmp{
public:
	Bmp(char *img_path, int lenght, int hight);
private:
	char *path;
    int l;
    int h;
    int add;
    int size;
    unsigned char *hex;

    Bmp open(char *path);
    void Bmp::set_header_image();
    unsigned char *Bmp::adapt(unsigned char *p);
};
#endif