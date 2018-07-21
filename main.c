#include "color.h"

#define L 1
#define H 1

int main(){
    fic=fopen("1px.bmp","wba");

    set_header_image(L,H);

    color x=rgb(0,0,255);
    fwrite(&x,3,1,fic);

    set_footer_image(L,H);

    fclose(fic);
    return 0;
}

