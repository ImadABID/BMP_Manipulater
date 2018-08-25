# BMP_Manipulater
<h2>Presentation</h2>
BMP_MANIPULATER is a library which allow us to do somme manipulations on bmp image. It is written in langage C and created by Imad ABID in Summer of 2018. 

<h2>How we can use it<h2>
    It easy to use this library you have just to respect this three steps:
    <h3>Initialisation</h3>
    if you want to creat a new image use: <br>
        <code>image set_image(char *img_path, int lenght, int hight);</code>
    if this you want to modificate an existing image use:<br>
        <code>image open(char *path);</code>

    <h3>Traitement</h3>
    for Now there is just two basic functions:<br>
    <code>void put_pixel(pixel px);</code> this function add a pixel (px) to the image.<br>
    <code>pixel get_pixel(image img, int x, int y);</code> this function return the pixel which has the coordinates(x,y) from the image img.<br>

    <h3>Save</h3>
    All the modifications are at the level of RAM so you to use <code>void save_image(image img);</code> to save the image.

<h2>The types of variables that you have to know<h2>
<code><pre>
    typedef struct structure2{
        char *path;
        int l;
        int h;
        int add;
        int size;
        unsigned char *hex;
    }image;

    typedef struct structure_of_color{
        unsigned char o1;
        unsigned char o2;
        unsigned char o3;
    }color;

    typedef struct structure_of_pixel{
        image img;
        int x;
        int y;
        color couleur;
    }pixel;
</pre></code>

<h2>Contact me<h2>
If you want to contacte me you can use : <a href="emailto:imad.abied@gmail.com">imad.abied@gmail.com</a>