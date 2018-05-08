#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include "libfractal.h"
#include "header.h"

#define LINE_MAX_LENGTH=64*sizeof(char)+2*sizeof(unsigned int)+2*sizeof(double)

static int DFLAG=0;
static int MAXTHREADS=5;
static double BiggestMean=0;
queue_t * Buff;//buffer contenant les fractales à calculer

int err;

int main(int argc, char** argv){

//Test d'entrée
	if(argc<3){
	printf(stderr,"%s [-d] [--maxthreads n] file1 [file 2 ...] fileOut\n",argv[0]);
	return(EXIT_FAILURE);
	}

int begin_argc=1;
int i;

//arg D
	for(int i=1;i<3;i++){
		if(strcomp("-d",argv[i])==0){
		DFLAG=1;
		begin_argc++;
		}

//TODO last argment must be out file

//arg maxthreads
		if(strcomp("--maxthreads",argv[i])==0){
		if(i>=argc || !isdigit(argv[i]){
		printf(stderr,"%s : error : invalid or missing number after --maxthreads",argv[i]);
		exit(EXIT_FAILURE);
		}
		MAXTHREADS=atoi(argv[i+1]);
		begin_argc+=2;
		}
	}

	if(argc-begin_argc<2){
	printf(stderr,"Missing arquments\n %s [-d] [--maxthreads n] file1 [file 2 ...] 		fileOut\n",argv[0]);
	return(EXIT_FAILURE);
	}


//alloue le buff de fract
	Buff =(queue_t)malloc(sizeof(queue_t));
	if(Buff==NULL){
	error("malloc of Buff");
	}
	queueInit(Buff,MAXHTREADS);



            
 //alloue threads de lecture
	int numFiles=argc-begin_argc-1;
	pthread_t reader_threads[numFiles];
	for(i=0;i<numFiles;i++){
	err=pthread_create(&reader_threads[i],NULL,&read_input,argv[i+begin_argc]);
	        if(err!=0){
        	        error("pthread create");
        	}
	}
	
//crée les threads de calcul
        pthread_t calcul_threads[MAXTHREADS];
        
        //alloue les threads de calcul
        for(i=0;i<MAXTHREADS;i++){
        err=pthread_create(&calcul_threads[i],NULL,&calculate_fract,NULL);
                if(err!=0){
        	error("pthread create");
        	}
        }	
//attent la completion des threads de lectures
	for(i=0;i<numFiles;i++){
	err=pthread_join(reader_threads[i],NULL);
	        if(err!=0){
        	        error("pthread join");
        	}
	}
}

/*
*
*/
void read_input(char * filename){

if(strcomp("-",filename)==0){
filename="stdin";
}

FILE *file = fopen(filename,"r");

if(file ==NULL){
printf(stderr,"error : can't open %s",filename);
exit(EXIT_FAILURE);
}
while(!eof ){

read_line(file);

}
fclose(file);


}


void read_line(FILE * file){
//TODO
//create struct
	queueAdd(Buff,frac);

}

void calculate_fractal(){
	fractal_t *fract;
	if(fract=queueGet(Buff)==NULL){
	error("queue get");
	}
	int x,y,w,h;
	w = fractal_get_width(f);
    	h = fractal_get_height(f);
	for(x=0;x<w;x++ ){
		for(y=0;y<h;y++){
		fractal_set_value(fract,x,y,fractal_compute_value(fract,x,y));
		}
	}
	s
	stack_add(Stack, fract);
}

/*
 * La section suivante contient les fonctions correspondant 
 * à la structure queue 
 *
*/


int queueInit(queue_t *queue,int n){
	int err;
	err=sem_init(&(queue->empty_slots), 0, n);      /* Au début, n slots vides */
    	
    	err=sem_init(&(queue->items), 0, 0);      /* Au début, rien à consommer */
    	
	err=pthread_mutex_init(&(queue->mutex),null);
	queue->n=n;
	queue->buff = (fractal_t **) calloc(n,sizof(fractal_t*));
	if(queue->buff==NULL){
		return -1;
	}
	queue_t->front=queue_t->rear=0;
	return 0;
	
}

void queueFree(queue_t *queue){
	free(queue);
}

int queueAdd(queue_t *queue, fractal_t *f){
	int err
	err=sem_wait(&(queue->empty_slots));
	
	err=pthread_mutex_lock(&(queue->mutex));
	
	//section critique
	queue->rear=((queue->rear))%(sp->n);
	queue->buff[queue->rear]=f;
	
	err=pthread_mutex_unlock(&(queue->mutex));
	err=sem_post(&(queue->items));
	return 0;
	
}

fractal_t *queueGet(queue_t *queue){
	err=sem_wait(&(queue->items));
	err=pthread_mutex_lock(&(queue->mutex));
	
	fractal_t *fract=(queue->buf)[(queue->front+1)%(queue->n)];
	queue->front++;
	
	err=pthread_mutex_unlock(&(queue->mutex));
	err=sem_post(&(queue->empty_slots));
	return fract;
}
void error(char * msg){
	printf(stderr,"error : %s",msg);
 	exit(EXIT_FAILURE);
}




