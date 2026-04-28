#include <stdio.h>

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources: \n");
    for (int j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Safety Algorithm
    int finish[n], safe_seq[n];
    for (int i = 0; i < n; i++) finish[i] = 0;

    int work[r];
    for (int j = 0; j < r; j++) work[j] = avail[j];

    int count = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (finish[i]) continue;

            // Check if need[i] <= work
            int can_allocate = 1;
            for (int j = 0; j < r; j++) {
                if (need[i][j] > work[j]) {
                    can_allocate = 0;
                    break;
                }
            }

            if (can_allocate) {
                // Simulate allocation: add its resources back to work
                for (int j = 0; j < r; j++)
                    work[j] += alloc[i][j];

                safe_seq[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }

        // No process could be allocated — unsafe state
        if (!found) break;
    }

    if (count == n) {
        printf("System is in a SAFE STATE.\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d", safe_seq[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    } else {
        printf("System is NOT in a safe state (Deadlock may occur).\n");
    }

    return 0;
}

// Step 1: Input and Initialize

// Read the Allocation matrix (Alloc), Maximum requirement matrix (Max), and Available resources array (Avail).

// Calculate the Need Matrix: For every process i and resource j, calculate:
// Need[i][j] = Max[i][j] - Alloc[i][j]

// Initialize a Work array of size r to keep track of current available resources:
// Work[j] = Avail[j] for all j.

// Initialize a Finish array of size n to keep track of completed processes:
// Finish[i] = 0 (False) for all i.

// Initialize count = 0 to track how many processes have been successfully sequenced.

// Step 2: Find a Runnable Process

// Search through all processes (i from 0 to n-1) to find a process that satisfies both of the following conditions:

// Finish[i] == 0 (The process has not finished yet).

// Need[i][j] <= Work[j] for all resource types j (Its resource needs can be satisfied by currently available Work).

// Step 3: Execute and Release Resources

// If a process i is found that meets the conditions in Step 2:

// Simulate its execution and release its currently allocated resources back to the pool:
// Work[j] = Work[j] + Alloc[i][j] for all j.

// Mark the process as finished: Finish[i] = 1 (True).

// Add process i to the safe_sequence array.

// Increment count by 1 (count++).

// Go back to Step 2 to find the next process.

// Step 4: Handle Unsafe Condition

// If no process i can be found in Step 2 that satisfies the conditions, stop searching and break out of the loop.

// Step 5: Check System State (Safe or Unsafe)

// If count == n (meaning all processes have Finish[i] == 1):

// The system is in a SAFE STATE.

// Print the safe_sequence.

// Else (meaning some processes could not finish):

// The system is in an UNSAFE STATE and deadlock may occur