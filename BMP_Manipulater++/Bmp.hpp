#if ! defined(__BMP__)
#define(__BMP__)

#define EN_TETE_SIZE 54
#define RAM_MAX 26214400 // 25Mo

class Bmp{
public:
	Bmp();
private:
	char *path;
    int l;
    int h;
    int add;
    int size;
    unsigned char *hex;

    void Bmp::set_header_image();
    unsigned char *Bmp::adapt(unsigned char *p);
};
#endif