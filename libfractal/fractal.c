#include <stdlib.h>
#include <string.h>
#include "fractal.h"

//definition of posint in fractal.h

int fractal_new(fractal_t* ptr,posint H, posint W, char* n, double a, double b){
	ptr = (fractal_t *) malloc(sizeof(fractal_t));
	if(ptr == NULL) return -1;

	//if(length(n)>64){do something/ not defined yet}
	ptr->name=n;

	ptr->a=a;
	ptr->b=b;
	ptr->height=H;
	ptr->width=W;

	posint **arr;
	if((arr=(posint **)malloc(sizeof(posint *)*W))==NULL)//rows
	return -1;
	
	int i;	
	for(i=0;i<W;i++){
	if((arr[i]=(posint *)malloc(sizeof(posint)*R))==NULL)//columns
	return -1;
	}
	
	ptr->pict=arr;
	return 0;
}

void fractal_free(fractal_t* fract){
free(fract);
}

char *fractal_get_name(fractal_t *f){
return f->name;
}

//x=row,y=column
int fractal_get_value(fractal_t *f,posint x,posint y){
if(f==NULL || x>f->width || y>f->height)
return -1;
return (f->pict)[x][y];
}

//x=row,y=column
int fractal_set_value(fractal_t *f,posint x,posint y, posint value){
if(f==NULL || x>f->width || y>f->height)
return -1;
(f->pict)[x][y]=value;
return 0;

}

int fractal_get_width(fractal_t *f){
if(f==NULL) return -1;
return f->width;
}

int fractal_get_height(fractal_t *f){
if(f==NULL) return -1;
return f->height;
}

double fractal_get_a(fractal_t *f){
if(f==NULL) return -1;
return f->a;
}

double fractal_get_b(fractal_t *f){
if(f==NULL) return -1;
return f->b;
}




