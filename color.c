#include "color.h"

image set_image(char *img_path, int img_size, int lenght, int hight){
    image img;
    img.path=malloc(255); img.path=img_path;
    img.size=img_size;
    img.l= lenght;
    img.h= hight;
    return img;
}

image open(char *path){
    FILE *f=fopen(path,"rb");
        //size
        unsigned char *ps=malloc(4);
        fseek(f,2,SEEK_SET);
        fread(ps,1,4,f);
        ps=adapt(ps);

        //Length
        fseek(f,18,SEEK_SET);
        unsigned char *pl=malloc(4);
        fread(pl,1,4,f);
        pl=adapt(pl);

        //Hight
        fseek(f,22,SEEK_SET);
        unsigned char *ph=malloc(4);
        fread(ph,1,4,f);
        ph=adapt(ph);
    fclose(f);

    printf("\n%d\n",HtoD(ph));

    return set_image(path, HtoD(ps), HtoD(pl), HtoD(ph));
}

void set_header_image(image img){

}

void set_footer_image(image img){

}

color rgb(unsigned char o1, unsigned char o2, unsigned char o3){
    color c;
    c.o1=o3; c.o2=o2; c.o3=o1;
    return c;
}


unsigned char *adapt(unsigned char *p){
    unsigned char *q=malloc(4);
    int i;
    for(i=0;i<4;i++){
        q[i]=p[3-i];
    }
    return q;
}


bool is_gray_background(pixel px){

    return false;
}