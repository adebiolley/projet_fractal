#include <pthread.h>
#include <stdlib.h>
#include "fractal.h"


int fractal_new(fractal_t* ptr,unsigned int H, unsigned int W, name_t n, double a, double b){
	ptr = (fractal_t *) malloc(sizeof(fractal_t));
	if(ptr == NULL) return 1;
	ptr->a=a;
	ptr->b=b;
	ptr->pict_height=H;
	ptr->pict_width=W;
	ptr->name=n;
	//ptr->pict=(char **)malloc(a*b*sizeof(char));
	return 0;
}

void fractal_free(fractal_t* fract){
free(fract);
}

char *fractal_get_name(fractal_t *f){
 return (f->name).str;
}




int main(int argc, char **argv){


}



