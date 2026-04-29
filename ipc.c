//Program Code:
//sender.c

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SharedMemSize 50
void main()
{
    char c;
    int shmid;
    key_t key;
    char *shared_memory; 
    key = 5677;
    //Create segment with the key specified
    if ((shmid = shmget(key, SharedMemSize, IPC_CREAT | 0666)) < 0)
    {
        //perror explains error code
        perror("shmget");
        exit(1);
    }
    //Attach the segment
    if((shared_memory= shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    sprintf(shared_memory," Welcome to Shared Memory");
    sleep(2);
    exit(0);
} 


//receiver.c

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SharedMemSize 50
void main()
{
    int shmid;
    key_t key;
    char *shared_memory;
    key = 5677;
    if ((shmid = shmget(key, SharedMemSize, 0666)) < 0) {
        perror("shmget");
        exit(1);
    } 
    //Attach the segment to our data space
    if((shared_memory = shmat(shmid, NULL, 0))==(char *) -1) {
        perror("shmat");
        exit(1);
    }
    //Read the message sender sent to the shared memory
    printf("Message Received: %s \n",shared_memory);
    exit(0);
}


// Algorithm: IPC - Shared Memory
// Part 1: Sender Process (Writer)
// Step 1: Initialize

// Define a unique key (e.g., 5677) to identify the shared memory segment.

// Define the required SharedMemSize (e.g., 50 bytes).

// Step 2: Create Shared Memory

// Use the system call shmget(key, size, IPC_CREAT | 0666) to create a new shared memory segment with read/write permissions.

// If the creation fails (returns a value < 0), print an error message and exit the program.

// Else, store the returned Shared Memory ID (shmid).

// Step 3: Attach Shared Memory

// Use the system call shmat(shmid, NULL, 0) to attach the shared memory segment to the sender's address space.

// If the attachment fails (returns -1), print an error message and exit.

// Else, assign the returned address to a character pointer (shared_memory).

// Step 4: Write Data

// Write the desired message (e.g., "Welcome to Shared Memory") into the shared_memory pointer using string formatting (sprintf).

// Step 5: Wait and Stop

// Sleep for a few seconds (to give the receiver time to access the memory).

// Terminate the sender process.

// Part 2: Receiver Process (Reader)
// Step 1: Initialize

// Define the exact same unique key (5677) and SharedMemSize (50) that the sender used.

// Step 2: Access Shared Memory

// Use the system call shmget(key, size, 0666) to locate the already created shared memory segment. (Note: IPC_CREAT is not used here because the sender already created it).

// If it fails to find the segment (returns a value < 0), print an error message and exit.

// Else, store the returned Shared Memory ID (shmid).

// Step 3: Attach Shared Memory

// Use the system call shmat(shmid, NULL, 0) to attach the shared memory segment to the receiver's address space.

// If the attachment fails (returns -1), print an error message and exit.

// Else, assign the returned address to a character pointer (shared_memory).

// Step 4: Read Data

// Read the message directly from the shared_memory pointer and print it to the screen ("Message Received: ...").

// Step 5: Stop

// Terminate the receiver process