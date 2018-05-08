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


/*
*pthread_mutex_t=mutex_buffer;
*sem_t buff_full;
*sem_t buff_empty;
*/
int err;

int main(int argc, char** argv){

//Test d'entrée
	if(argc<3){
	printf(stderr,"%s [-d] [--maxthreads n] file1 [file 2 ...] fileOut\n",argv[0]);
	return(EXIT_SUCCESS);
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

//alloue le buff de fract
	Buff =(queue_t)malloc(sizeof(queue_t));
	if(Buff==NULL){
	printf(stderr,"error : malloc of Buff");
	exit(EXIT_FAILURE);
	}
	queueInit(Buff,MAXHTREADS);



            
        //alloue threads de lecture
	int N_thread_read=argc-begin_argc;
	pthread_t reader_threads[N_thread_read];
	for(i=0;i<N_thread_read;i++){
	err=pthread_create(&reader_threads[i],NULL,&read_input,argv[i+begin_argc]);
	        if(err!=0){
        	        printf(stderr,"error : pthread_create");
        	        exit(EXIT_FAILURE);
        	}
	}
	
//crée les threads de calcul
        pthread_t calcul_threads[MAXTHREADS];
        
        //alloue les threads de calcul
        for(i=0;i<MAXTHREADS;i++){
        err=pthread_create(&calcul_threads[i],NULL,&calculate_fract,NULL);
                if(err!=0){
        	printf(stderr,"error : pthread_create");
        	exit(EXIT_FAILURE);
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



void write_fractal_to_buffer(fractal_t *fract){
//TODO
}

void read_line(FILE * file){
//TODO
//create struct


//section critique
write_fractal_to_buffer(fractal);

}

/*
 * La section suivante contient les fonctions correspondant 
 * à la structure queue 
 *
*/

void queueInit(queue_t *queue,int n){
	
	sem_init(&(queue->empty_slots), 0, n);      /* Au début, n slots vides */
    	
    	sem_init(&(queue->items), 0, 0);      /* Au début, rien à consommer */
    	
	pthread_mutex_init(&(queue->mutex),null);
	queue->n=n;
	queue->buff = (fractal_t **) calloc(n,sizof(fractal_t*));
	if(queue->buff==NULL){
		printf(stderr,"error : calloc");
        	exit(EXIT_FAILURE);
	}
	queue_t->front=queue_t->rear=0;
	
}

void queueFree(queue_t *queue){
	free(queue);
}

void queueAdd(queue_t *queue, fractal_t *f){
	sem_wait(&(queue->empty_slots));
	
	pthread_mutex_lock(&(queue->mutex));
	
	//section critique
	queue->rear=((queue->rear))%(sp->n);
	queue->buff[queue->rear]=f;
	
	pthread_mutex_unlock(&(queue->mutex));
	sem_post(&(queue->items));
	
}

fractal_t *queueGet(queue_t *queue){
	sem_wait(&(queue->items));
	pthread_mutex_lock(&(queue->mutex));
	
	fractal_t *fract=(queue->buf)[(queue->front+1)%(queue->n)];
	queue->front++;
	pthread_mutex_unlock(&(queue->mutex));
	sem_post(&(queue->empty_slots));
}


