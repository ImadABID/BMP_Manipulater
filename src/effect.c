#include "effect.h"

image merge(image img1, image img2, char *output_path){
    
    int l=((img1.l>img2.l)?img2.l:img1.l);
    int h=((img1.h>img2.h)?img2.h:img1.h);

    image img_out=set_image(output_path,l,h);
    pixel px;

    bool is_img1=true;
    bool adapt=false;
    if(l%2==0) adapt=true;

    for(int j=0; j<h; j++){
        if(adapt) is_img1=!is_img1;
        for(int i=0; i<l; i++){
            if(is_img1){
                px=get_pixel(img1,i,j);
            }else{
                px=get_pixel(img2,i,j);
            }
            is_img1=!is_img1;

            px.img=img_out;
            put_pixel(px);

        }
    }
    return img_out;
}
