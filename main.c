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
fractal_t** Fract_buff;//buffer contenant les fractales à calculer

sbuf_t

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
	Fract_buff =(fractal_t)malloc((MAXTHREADS+1)*sizeof(fractal_t*));
	if(Fract_buff==NULL){
	printf(stderr,"error : malloc of Fract_buff");
	exit(EXIT_FAILURE);
	}

	err = pthread_mutex_init(&mutex_buffer,NULL);
	if(err!=0){
	printf(stderr,"error : mutex init");
	exit(EXIT_FAILURE);
	}

            
        //alloue threads de lecture
	int N_thread_read=argc-begin_argc;
	pthread_t reader_threads[N_thread_read];
	for(i=0;i<N_thread_read;i++){
	err=pthread_create(&reader_threads[i],NULL,&read_input,argv[i+begin_argc]);
	        if(err!=0){
        	printf(stderr,"error : mutex init");
        	exit(EXIT_FAILURE);
        	}
	}
	
	/*
	*
	*/
	
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

