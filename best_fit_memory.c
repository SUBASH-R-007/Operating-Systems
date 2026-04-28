//Best Fit

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
        int bestIndex = -1;
        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }
        if(bestIndex != -1) {
            int fragment = blockSize[bestIndex] - processSize[i];
            printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d\n",
                   i + 1, processSize[i], bestIndex + 1, original[bestIndex], fragment);
            blockSize[bestIndex] -= processSize[i]; 
        } else {
            printf("Process %d of size %d is not allocated\n",
                   i + 1, processSize[i]);
        }
    }
    return 0;
}

// Algorithm: Best Fit Memory Allocation
// Step 1: Start and Initialize

// Read the total number of memory blocks, m

// For each block j (from 0 to m-1), read its size and store it in an array blockSize[].

// (Optional for display purposes) Copy these sizes into an original[] array to remember the initial size of each block.

// Read the total number of processes, n.

// For each process i (from 0 to n-1), read its required memory size and store it in an array processSize[].

// Step 2: Process Allocation Loop
// Repeat Steps 3 and 4 for each process i from 0 to n-1:

// Step 3: Search for the "Best Fit" Block

// Initialize bestIndex = -1. This variable will store the index of the memory block that leaves the smallest leftover space.

// Loop through all memory blocks j from 0 to m-1:

// If the current block has enough space (blockSize[j] >= processSize[i]):

// If this is the very first block found that fits (bestIndex == -1) OR if this block is smaller (tighter fit) than the previously recorded best block (blockSize[j] < blockSize[bestIndex]):

// Update bestIndex = j.

// Step 4: Allocate or Wait

// If a suitable block was found (bestIndex != -1):

// Calculate the remaining space (Internal Fragmentation):
// fragment = blockSize[bestIndex] - processSize[i]

// Print the allocation message indicating Process i is allocated to Block bestIndex.

// Crucial Update: Deduct the allocated space from that block's available size so the remainder can potentially be used later:
// blockSize[bestIndex] = blockSize[bestIndex] - processSize[i]

// Else (meaning bestIndex is still -1 because no block was large enough):

// Print that Process i must wait and is not allocated.

// Step 5: Stop

// Terminate the algorithm once all n processes have been checked.