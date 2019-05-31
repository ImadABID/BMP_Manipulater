# Photograph the future
<h2>Presentation</h2>
Imaging If we take a 1000x500 as a size of a picture, there is 256^(3*1000*500) image possible. In those images, we are going to find the cars, the cities, the clothes …, of the future. Those images will inspire us to design everything in the future. “Photograph the future” is an open source project, which generate those images, and predict which one is valuable for us.
<h1>Documentation</h1>
<h2>Langage C++</h2>
<h3>Class Bmp</h3>
<h4>class header</h4>
<h4>Open an image</h4>
to open an image use the constructer:
<code>
    Bmp(char *img_path, int lenght, int hight);
</code>
if the image is alerdy in the path, use:
<code>
    Bmp(char *img_path, -1, -1);
</code>
<h2>Langage C</h2>
<h3>How we can use it</h3>
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
    All the modifications are at these level in RAM so you have to use <code>void save_image(image img);</code> to save the image.

<h3>The types of variables that you have to know</h3>
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

<h2>Contact me</h2>
If you want to contacte me you can use : <a href="mailto:imad.abied@gmail.com">imad.abied@gmail.com</a>
