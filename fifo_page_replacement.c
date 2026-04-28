//FIFO 

#include <stdio.h>
int main() {
    int n, frames, i, j;
    printf("Enter number of pages in reference string: \n");
    scanf("%d", &n);
    int ref[n];
    printf("Enter the reference string: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &ref[i]);
    }
    printf("Enter number of frames: \n");
    scanf("%d", &frames);
    int frame[frames];
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    int pageFaults = 0, pageHits = 0;
    int front = 0;
    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                pageHits++;
                break;
            }
        }
        if(!found) {
            frame[front] = ref[i];
            front = (front + 1) % frames;
            pageFaults++;
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    return 0;
}

// Here is the step-by-step algorithm for the First-In, First-Out (FIFO) Page Replacement Algorithm, written clearly for an exam based on your C code logic.

// Algorithm: FIFO Page Replacement
// Step 1: Start and Initialize

// Read the number of pages in the reference string, n.

// Read the reference string into an array, ref[n].

// Read the number of available memory frames, frames.

// Create an array frame[] of size frames and initialize all its elements to -1 (indicating empty frames).

// Initialize pageFaults = 0 and pageHits = 0.

// Initialize a pointer front = 0 to keep track of the oldest page in the memory (First-In).

// Step 2: Process the Reference String
// Repeat Steps 3 and 4 for each page ref[i] in the reference string (loop i from 0 to n-1):

// Step 3: Check for a Page Hit

// Search for the current page ref[i] within the frame[] array.

// If the page is found:

// It is a Page Hit. Increment the hit counter: pageHits++.

// Stop searching and move to the next page in the reference string (continue the main loop).

// Step 4: Handle a Page Fault (Replacement)

// If the page is not found in the frame[] array:

// It is a Page Fault. Increment the fault counter: pageFaults++.

// Insert the new page ref[i] into the frame pointed to by the front pointer:
// frame[front] = ref[i]

// Update the front pointer using modulo arithmetic to ensure it wraps around in a circular manner when it reaches the end of the frames:
// front = (front + 1) % frames

// Step 5: Display Results and Stop

// Print the total number of pageFaults.

// Print the total number of pageHits.

// Terminate the algorithm