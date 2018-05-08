#ifndef _HEADER_H
#define _HEADER_H



void read_input(char * filename);

void read_line(FILE * file);

void write_fractal_to_buffer( fractal_t * fract);

void calculate_fractal(fractal_t* fract);

//void read_fractal_from_buffer();

//void write_fractal_to_list

//void write_output 

typedef struct{
int n; //taille du buffer
int front;
int rear;
fractal_t **buff;
pthread_mutex_t mutex; //protège accès au buffer
sem_t empty_slots; //nombre de places libres
sem_t items;// Nombre d'item dans le buffer

}queue_t



void queueInit(queue_t *queue,int n);


void queueFree(queue_t *queue);


void queueAdd(queue_t *queue, fractal_t *f);

//@return :  queue->tail->fract, or NULL if queue is empty
fractal_t *queueGet(queue_t *queue);





#endif
