#ifndef _HEADER_FRACTAL_
#define _HEADER_FRACTAL_

struct fractal{

unsigned int pict_height;
unsigned int pict_width;
char name[64];
double a;
double b;

}fractal_t

/*
 * allocates a new struct fractal to ptr
 * @return : 0 on succes, 1 if an error occured
/*
int fractal_new(void* ptr);


/*
 * frees the memory allocated to fract
 * @return : 0 if the memory was correctly freed, 1 if an error occured
/*
int fractal_free(fractal_t* fract);

/*
 * returns the name of f
/*
char *fractal_get_name(fractal_t *f);

/*
 * returns the value of the pixel from f of coordinates x and y
 * if an error occured, returns -1
/*
int fractal_get_value(fractal_t *f,int x,int y);

int fratal_set_value(fractal_t *f,int x,int y,int value);

int fractal_get_width(fractal_t *f);

int fractal_get_heigth(fractal_t *f);

double fractal_get_a(fractal_t *f);

double fractal_get_b(fractal_t *f);





#endif
