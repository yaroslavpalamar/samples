// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

/*
	1. semaphore gives access to limited number of threads to some common resource
	2. int sem_init(sem_t *sem, int pshared, unsigned int value); init unnamed semaphore
	3. creat two thread with small delay 1 second
	4. in shared resource wait more then time between process creation for example 2 seconds
	5. check that second process don't access shared resource when first process was inside shared resource
	6. pthread_joid() and sem_destroy(&mutex).
*/
  
sem_t mutex; 
  
void* thread(void* arg) 
{ 
	//wait 
	sem_wait(&mutex); 
	printf("\nEntered..\n"); 
  
	//critical section 
	sleep(2); 
      
	//signal 
	printf("\nJust Exiting...\n"); 
	sem_post(&mutex); 
	pthread_exit(NULL);
} 
  
  
int main() 
{ 
	sem_init(&mutex, 0, 1);
	pthread_t t1,t2; 
	pthread_create(&t1,NULL,thread,NULL); 
	sleep(1); 	
	pthread_create(&t2,NULL,thread,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&mutex);
	return 0; 
} 
