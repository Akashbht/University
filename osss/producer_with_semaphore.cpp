#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <pthread.h>
// #include <semaphore.h>
#define BUFF_SIZE 5
int buffer[BUFF_SIZE];int in = 0, out = 0;
sem_t empty;   sem_t full;    sem_t mutex;   
void* producer(void* arg) {
    while (1) {
        int item = rand() % 100;  // Produce an item
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFF_SIZE;
      sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}
void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        int item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFF_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
       sleep(2);
    }
}
int main() {
    sem_init(&empty, 0, BUFF_SIZE);   
    sem_init(&full, 0, 0);            
    sem_init(&mutex, 0, 1);       
    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
   pthread_join(prod, NULL);
    pthread_join(cons, NULL);
   sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
return 0;
}
