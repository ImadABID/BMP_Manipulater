#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"

int main(){

    image img1=open("img1.bmp");
    image img2=open("img2.bmp");

    int l=((img1.l>img2.l)?img2.l:img1.l);
    int h=((img1.h>img2.h)?img2.h:img1.h);

    image imgOut=set_image("imgOut.bmp",l,h);
    
    pixel px;

    bool is_img1=true;
    bool adapt=false;
    if(l%2==0) adapt=true;

    for(int j=0; j<h; j++){
        if(adapt) is_img1=!is_img1;
        for(int i=0; i<l; i++){
            if(is_img1){
                px=get_pixel(img1,i,j);
                is_img1=!is_img1;
            }else{
                px=get_pixel(img2,i,j);
                is_img1=!is_img1;
            }

            px.img=imgOut;
            put_pixel(px);

        }
    }

    save_image(imgOut);

    return 0;
}