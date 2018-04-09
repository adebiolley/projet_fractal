#ifndef _HEADER_FRACTAL_
#define _HEADER_FRACTAL_

typedef struct fractal fractal_t;
typedef struct name name_t;

struct name{
char str[64];
};

struct fractal{

unsigned int pict_height;
unsigned int pict_width;
name_t name;
double a;
double b;
unsigned int **pict;
};


/*
 * allocates a new struct fractal to ptr
 * @return : 0 on succes, 1 if an error occured
*/
int fractal_new(fractal_t* ptr,unsigned int H, unsigned int W, name_t name, double a, double b);


/*
 * frees the memory allocated to fract
 * @return : 0 if the memory was correctly freed, 1 if an error occured
*/
void fractal_free(fractal_t* fract);

/*
 * returns the name of f
*/
char *fractal_get_name(fractal_t *f);

/*
 * returns the value of the pixel from f of coordinates x and y
 * if an error occured, returns -1
*/
int fractal_get_value(fractal_t *f,int x,int y);

/*
 * Sets the value of the pixel of coordinates x and y 
 * in the fractal f to the value value
 * returns 0 on succes, 1 if an error occured
*/
int fratal_set_value(fractal_t *f,int x,int y,int value);

/*
 * returns the width of the picture, in pixels 
 * if an error occured, returns -1
*/
int fractal_get_width(fractal_t *f);

/*
 * returns the heigth of the picture, in pixels 
 * if an error occured, returns -1
*/
int fractal_get_heigth(fractal_t *f);

/*
 *returns the real component of the fractal
 *
*/
double fractal_get_a(fractal_t *f);

/*
 *returns the imaginary component of the fractal
*/
double fractal_get_b(fractal_t *f);

//fractal_compute_value



#endif
