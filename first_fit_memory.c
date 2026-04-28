//First Fit

#include <stdio.h>
int main() {
    int m, n, i, j;
    printf("Enter number of memory blocks:\n");
    scanf("%d", &m);
    int blockSize[m], original[m];
    printf("Enter size of each block:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        original[i] = blockSize[i]; 
    }
    printf("Enter number of processes:\n");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
    for(i = 0; i < n; i++) {
        int flag = 0;
        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                int fragment = blockSize[j] - processSize[i];
                printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d\n",
                       i + 1, processSize[i], j + 1, original[j], fragment);
                blockSize[j] -= processSize[i]; 
                flag = 1;
                break;
            }
        }
        if(!flag) {
            printf("Process %d of size %d is not allocated\n",
                   i + 1, processSize[i]);
        }
    }
    return 0;
}

// Step 1: Start and Initialize

// Read the total number of memory blocks, m

// For each block j (from 0 to m-1), read its size and store it in an array blockSize[].

// (Optional for display purposes) Copy these sizes into an original[] array to remember the initial size of each block.

// Read the total number of processes, n.

// For each process i (from 0 to n-1), read its required memory size and store it in an array processSize[].

// Step 2: Process Allocation Loop
// Repeat Steps 3 and 4 for each process i from 0 to n-1:

// Step 3: Search for the First Fit Block

// Initialize a flag = 0 to track whether the current process gets successfully allocated.

// Loop through the memory blocks j from 0 to m-1 sequentially:

// If the current block has enough space (blockSize[j] >= processSize[i]):

// Calculate the remaining space (Internal Fragmentation):
// fragment = blockSize[j] - processSize[i]

// Print the allocation message indicating Process i is allocated to Block j.

// Crucial Update: Deduct the allocated space from the block's available size so it can potentially be used by future processes:
// blockSize[j] = blockSize[j] - processSize[i]

// Mark the allocation as successful: flag = 1.

// Break out of the block-searching loop immediately (This is the "First Fit" behavior—you stop searching as soon as you find the first capable block).

// Step 4: Handle Unallocated Processes

// If after checking all blocks the flag remains 0 (meaning no single block was large enough):

// Print that Process i must wait and is not allocated.

// Step 5: Stop

// Terminate the algorithm once all n processes have been checked.