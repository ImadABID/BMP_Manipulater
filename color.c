#include "color.h"

image set_image(char *img_path, int lenght, hight){
    image img
    img.path=img_path;
    img.l= lenght;
    img.h= hight;
    return img;
}

image open(char *path){
    int l,h;
    FILE *f=fopen(path,"rb");
    
    fclose(f)
}

void set_header_image(image img){

}

void set_footer_image(image img){

}

color rgb(char o1, char o2, char o3){
    color c;
    c.o1=o3; c.o2=o2; c.o3=o1;
    return c;
}

void inverse(image img){
    FILE *f=fopen(img.path,"rb");
        size=sizeof_image(img);
        char *p=malloc(size);

        int i;
        for(i=0;i<size;i++){
            fread=(&p[size-i],1,1,f);
        }
    fclose(f);

    FILE *fn=fopen(img.path,"wb");
        fwrite(p,1,size,fn);
    fclose(fn);
}

bool is_gray_background(pixel px){

    return false;
}