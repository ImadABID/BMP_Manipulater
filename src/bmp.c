#include "bmp.h"

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
    unsigned char p2oct[2]={66,77};
    FILE *f=fopen(img.path,"wb");
        fwrite(p2oct,1,2,f); //signature bmp
        
        fwrite(adapt(DtoH(img.size)),1,4,f); //size of file

        p2oct[0]=0; p2oct[1]=0;
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);

        p2oct[0]=54;
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);
        p2oct[0]=0; 
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);

        p2oct[0]=40; 
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);
        p2oct[0]=0; 
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);

        fwrite(adapt(DtoH(img.l)),1,4,f); //lenght
        fwrite(adapt(DtoH(img.h)),1,4,f); //hight

        p2oct[0]=1; 
        fwrite(p2oct,1,2,f); fwrite(p2oct,1,2,f);

        int i; p2oct[0]=0;
        for(i=0;i<13;i++){
            fwrite(p2oct,1,2,f);
        }
    
    fclose(f);
}

void set_footer_image(image img){
    unsigned char *p=malloc(2);
    p[0]=0; p[1]=0;

    FILE *f=fopen(img.path,"ab");
        fwrite(p,1,2,f);
    fclose(f);
}

unsigned char *adapt(unsigned char *p){
    unsigned char *q=malloc(4);
    int i;
    for(i=0;i<4;i++){
        q[i]=p[3-i];
    }
    return q;
}