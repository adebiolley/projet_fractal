#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#define OPTION_CHECKED
//#include "libfractal.h"

static int DFLAG=0;
static int MAXTHREADS;

int main(int argc, char** argv){
if(argc<3){
printf(stderr,"%s [-d] [--maxthreads n] file1 [file 2 ...] fileOut\n",argv[0]);
return(EXIT_SUCCESS);
}

int i;
for(int i=1;i<argc;i++){
if(strcomp("-d",argv[i])==0){
DFLAG=1;
argv[i]=OPTION_CHECKED;
}
//TODO last argment must be out file
if(strcomp("--maxthreads",argv[i])==0){
if(i>=argc || !isdigit(argv[i]){
printf(stderr,"%s : error : invalid or missing number after --maxthreads",argv[i]);
exit(EXIT_FAILURE);
}
MAXTHREADS=atoi(argv[i+1]);
argv[i]=OPTION_CHECKED;
i++;
argv[i]=OPTION_checked;
}

for(int i=1;i<argc;i++){
//add thread
read_input(argv[i]);
//TODO
}

void read_input(char * filename){
if(filename==NULL) return; 
//TODO add mutex, semaphore
}
