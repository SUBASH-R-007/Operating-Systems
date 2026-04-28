// Step 1: Start
// Initialize the program and declare arrays to store Arrival Time (AT), Burst Time (BT), Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT) for n processes.

// Step 2: Input Process Details

// Read the total number of processes, n.

// For each process i from 0 to n-1:

// Read the Arrival Time AT[i].

// Read the Burst Time BT[i].

// Step 3: Calculate Completion Time (CT)

// For the very first process (i = 0), it starts immediately upon arrival:

// CT[0] = AT[0] + BT[0]

// For the remaining processes (i = 1 to n-1), calculate CT based on CPU availability:

// If the current process arrives after the previous process has completed (AT[i] > CT[i-1]):
// The CPU was idle. The process starts at its own arrival time.

// CT[i] = AT[i] + BT[i]

// Else (the process arrived before the previous one finished):
// The process must wait and starts exactly when the previous process finishes.

// CT[i] = CT[i-1] + BT[i]

// Step 4: Calculate Turnaround Time (TAT) and Waiting Time (WT)

// Initialize totalTAT = 0 and totalWT = 0.

// For each process i from 0 to n-1:

// Calculate Turnaround Time: TAT[i] = CT[i] - AT[i]

// Calculate Waiting Time: WT[i] = TAT[i] - BT[i]

// Add to totals:

// totalTAT = totalTAT + TAT[i]

// totalWT = totalWT + WT[i]

// Step 5: Calculate Averages

// Calculate Average Turnaround Time = totalTAT / n

// Calculate Average Waiting Time = totalWT / n

// Step 6: Display Results

// Print the calculated Average Turnaround Time and Average Waiting Time.

// Step 7: Stop

// Terminate the algorithm.

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: \n");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: \n", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    float totalTAT = 0, totalWT = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);

    return 0;
}