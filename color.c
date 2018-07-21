#include "color.h"

void set_header_image( int l, int h){
    {char data[18]={66,77,58,0,0,0,0,0,0,0,54,0,0,0,40,0,0,0};
    fwrite(data,sizeof(char),18,fic);}

    fwrite(&l,2,1,fic);
    {int x=0; fwrite(&x,1,2,fic);}
    fwrite(&h,2,1,fic);

    {
        char data[30]={0,0,1,0,24,0,0,0,0,0,4,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0};
        fwrite(data,sizeof(char),30,fic);
    }
}

void set_footer_image(int l, int h){
    int i;
    int x=0;
    for(i=0;i<l*h;i++){
        fwrite(&x,sizeof(char),1,fic);
    }
}

color rgb(char o1, char o2, char o3){
    color c;
    c.o1=o3; c.o2=o2; c.o3=o1;
    return c;
}