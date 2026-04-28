//LRU

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
    int time[frames];   
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = -1;
    }
    int pageFaults = 0, pageHits = 0;
    int counter = 0;
    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                pageHits++;
                time[j] = counter++;  
                break;
            }
        }
        if(!found) {
            int lru_index = 0;
            for(j = 1; j < frames; j++) {
                if(time[j] < time[lru_index]) {
                    lru_index = j;
                }
            }
            frame[lru_index] = ref[i];
            time[lru_index] = counter++;
            pageFaults++;
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    return 0;
}

// Step 1: Start and Initialize

// Read the number of pages in the reference string, n.

// Read the reference string into an array, ref[n]

// Read the number of available memory frames, frames.

// Create two arrays: frame[] to store the pages, and time[] to track when each frame was last used.

// Initialize all elements of both frame[] and time[] to -1.

// Initialize pageFaults = 0 and pageHits = 0.

// Initialize a global counter = 0 to act as a logical clock.

// Step 2: Process the Reference String
// Repeat Steps 3 and 4 for each page ref[i] in the reference string (loop i from 0 to n-1):

// Step 3: Check for a Page Hit

// Search for the current page ref[i] within the frame[] array.

// If the page is found at index j:

// It is a Page Hit. Increment the hit counter: pageHits++.

// Crucial LRU Step: Update the time tracking for this frame to the current logical time: time[j] = counter.

// Increment the logical clock: counter++.

// Stop searching and move to the next page in the reference string.

// Step 4: Handle a Page Fault (Replacement)

// If the page is not found in the frame[] array:

// It is a Page Fault. Increment the fault counter: pageFaults++.

// Search the time[] array to find the frame with the minimum time value. This index represents the Least Recently Used page. Let this index be lru_index.

// Replace the old page with the new page: frame[lru_index] = ref[i].

// Update the time tracking for this newly loaded frame: time[lru_index] = counter.

// Increment the logical clock: counter++.

// Step 5: Display Results and Stop

// Print the total number of pageFaults.

// Print the total number of pageHits.

// Terminate the algorithm.