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
fractal_t **buff; //buffer partagé
int n; //taille du buffer
int front; //premier élement du buffer
int rear;//dernier élement du buffer
sem_t mutex; //protège accès au buffer
sem_t empty_slots; //nombre de places libres
sem_t items;// Nombre d'item dans le buffer

}sbuf_t

#endif
