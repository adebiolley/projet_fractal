#include <stdlib.h>
#include <string.h>
#include "fractal.h"

//definition of int in fractal.h

fractal_t* fractal_new(const char* n, int W, int H, double a, double b){
	fractal_t* ptr = (fractal_t *) malloc(sizeof(fractal_t));
	if(ptr == NULL) return NULL;

	//if(length(n)>64){do something/ not defined yet}
	ptr->name=n;

	ptr->a=a;
	ptr->b=b;
	ptr->height=H;
	ptr->width=W;

	int **arr;
	if((arr=(int **)malloc(sizeof(int *)*W))==NULL)//rows
	return NULL;
	
	int i;	
	for(i=0;i<W;i++){
	if((arr[i]=(int *)malloc(sizeof(int)*H))==NULL)//columns
	return NULL;
	}
	
	ptr->pict=arr;
	return ptr;
}

void fractal_free(fractal_t* fract){
free(fract);
}

const char *fractal_get_name(const fractal_t *f){
return f->name;
}

//x=row,y=column
int fractal_get_value(const fractal_t *f,int x,int y){
//if(f==NULL || x>f->width || y>f->height)
//return -1;
return (f->pict)[x][y];
}

//x=row,y=column
void fractal_set_value(fractal_t *f,int x,int y, int value){
//if(f==NULL || x>f->width || y>f->height)
//return -1;
(f->pict)[x][y]=value;
//return 0;

}

int fractal_get_width(const fractal_t *f){
//if(f==NULL) return -1;
return f->width;
}

int fractal_get_height(const fractal_t *f){
//if(f==NULL) return -1;
return f->height;
}

double fractal_get_a(const fractal_t *f){
//if(f==NULL) return -1;
return f->a;
}

double fractal_get_b(const fractal_t *f){
//if(f==NULL) return -1;
return f->b;
}




