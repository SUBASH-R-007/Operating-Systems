#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg)
{
    int item;
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        item = i;
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *arg)
{
    int item;

    for(int i = 0; i <BUFFER_SIZE; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}

// Algorithm: Producer-Consumer Problem
// Step 1: Initialization (Global State)

// Define a shared circular array buffer of size N (e.g., BUFFER_SIZE = 5).

// Initialize two index variables:

// in = 0 (Points to the next free slot for the Producer)

// out = 0 (Points to the next filled slot for the Consumer)

// Initialize three semaphores:

// empty = N (Counting semaphore: tracks available empty slots)

// full = 0 (Counting semaphore: tracks filled slots containing data)

// mutex = 1 (Binary semaphore: ensures mutual exclusion when accessing the shared buffer)

// Step 2: Producer Thread Algorithm
// Repeat the following for every item to be produced:

// Generate/produce a new item.

// Wait(empty): Decrease the empty count by 1. If empty is 0 (buffer is full), the producer is blocked until the consumer reads an item.

// Wait(mutex): Acquire the lock to enter the critical section safely.

// Critical Section:

// Insert the item into buffer[in].

// Update the index circularly: in = (in + 1) % N.

// Signal(mutex): Release the lock, exiting the critical section.

// Signal(full): Increase the full count by 1. This wakes up the consumer if it was sleeping.

// Step 3: Consumer Thread Algorithm
// Repeat the following for every item to be consumed:

// Wait(full): Decrease the full count by 1. If full is 0 (buffer is empty), the consumer is blocked until the producer adds an item.

// Wait(mutex): Acquire the lock to enter the critical section safely.

// Critical Section:

// Read the item from buffer[out].

// Update the index circularly: out = (out + 1) % N.

// Signal(mutex): Release the lock, exiting the critical section.

// Signal(empty): Increase the empty count by 1. This wakes up the producer if it was sleeping.

// Process/consume the retrieved item.

// Step 4: Main Driver Algorithm

// Initialize all semaphores (empty, full, mutex).

// Create the Producer thread and the Consumer thread concurrently.

// Wait for both threads to complete execution (using thread joins).

// Destroy the semaphores to free system resources.

// Terminate.