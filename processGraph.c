/*	AUTHOR: Todd Twiggs
*	DATE:	5 Nov 2015
*	COURSE:	CSCI 3232 - Systems Software
*	PROF:	Dr. Allen
*	ASSIGNMENT 7, QUESTION 2
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t AB, AC, BD, CE, BF, DE, EG, GH, FH;

void *funcA (void *arg) {
	printf("\nBeginning of process A\n");
	sleep(1);
	printf("End of process A\n");
	sem_post(&AB);
	sem_post(&AC);
}

void *funcB () {
	sem_wait(&AB);
	printf("Beginning of process B\n");
	sleep(1);
	printf("End of process B\n");
	sem_post(&BD);
	sem_post(&BF);
}

void *funcC (void *arg) {
	sem_wait(&AC);
	printf("Beginning of process C\n");
	sleep(1);
	printf("End of process C\n");
	sem_post(&CE);
}

void *funcD (void *arg) {
	sem_wait(&BD);
	printf("Beginning of process D\n");
	sleep(1);
	printf("End of process D\n");
	sem_post(&DE);
}

void *funcE (void *arg) {
	sem_wait(&CE);
	sem_wait(&DE);
	printf("Beginning of process E\n");
	sleep(1);
	printf("End of process E\n");
	sem_post(&EG);
}

void *funcF (void *arg) {
	sem_wait(&BF);
	printf("Beginning of process F\n");
	sleep(1);
	printf("End of process F\n");
	sem_post(&FH);
}

void *funcG (void *arg) {
	sem_wait(&EG);
	printf("Beginning of process G\n");
	sleep(1);
	printf("End of process G\n");
	sem_post(&GH);
}

void *funcH (void *arg) {
	sem_wait(&FH);
	sem_wait(&GH);
	printf("Beginning of process H\n");
	sleep(1);
	printf("End of process H\n\n");
}

int main(int argc, char *argv[]){
	
	sem_init(&AB, 1, 0);
	sem_init(&AC, 1, 0);
	sem_init(&BD, 1, 0);
	sem_init(&BF, 1, 0);
	sem_init(&CE, 1, 0);
	sem_init(&DE, 1, 0);
	sem_init(&EG, 1, 0);
	sem_init(&FH, 1, 0);
	sem_init(&GH, 1, 0);
	
	pthread_t A, B, C, D, E, F, G, H;
	
	pthread_create(&A, NULL, funcA, NULL);
	pthread_create(&B, NULL, funcB, NULL);
	pthread_create(&C, NULL, funcC, NULL);
	pthread_create(&D, NULL, funcD, NULL);
	pthread_create(&E, NULL, funcE, NULL);
	pthread_create(&F, NULL, funcF, NULL);
	pthread_create(&G, NULL, funcG, NULL);
	pthread_create(&H, NULL, funcH, NULL);
	
	pthread_join(A, NULL);
	pthread_join(B, NULL);
	pthread_join(C, NULL);
	pthread_join(D, NULL);
	pthread_join(E, NULL);
	pthread_join(F, NULL);
	pthread_join(G, NULL);
	pthread_join(H, NULL);
	
	return 0;
}


