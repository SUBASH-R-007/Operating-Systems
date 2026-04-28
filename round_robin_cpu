#include <stdio.h>

int main() {
    int n, tq;
    
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    
    printf("Enter Time Quantum: \n");
    scanf("%d", &tq);
    
    int at[n], bt[n], rem[n], ct[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: \n", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }
    
    int time = 0, done = 0;
    int tat[n], wt[n];
    
    while (done < n) {
        int progressed = 0;
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0 && at[i] <= time) {
                progressed = 1;
                if (rem[i] <= tq) {
                    time += rem[i];
                    rem[i] = 0;
                    ct[i] = time;
                    done++;
                } else {
                    time += tq;
                    rem[i] -= tq;
                }
            }
        }
        if (!progressed) time++;
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

// Step 1: Start and Initialize

// Read the total number of processes, n

// Read the Time Quantum, TQ.

// For each process i, input its Arrival Time (AT) and Burst Time (BT).

// Create an array called Remaining Time (Rem) and initialize it with the burst times: Rem[i] = BT[i].

// Initialize time = 0 and completed_processes = 0.

// Step 2: Process Execution Loop
// Repeat Steps 3 and 4 while completed_processes < n:

// Step 3: Scan and Execute Available Processes

// Initialize a flag progressed = 0 to track if any process executes in this cycle.

// Loop through all processes i from 0 to n-1:

// If the process has arrived (AT[i] <= time) AND is not yet finished (Rem[i] > 0):

// Set progressed = 1 (indicating the CPU is not idle).

// Condition A (Process finishes in this quantum): If Rem[i] <= TQ:

// Advance time: time = time + Rem[i]

// Mark process as finished: Rem[i] = 0

// Record Completion Time: CT[i] = time

// Increment completed_processes by 1.

// Condition B (Process needs more time): If Rem[i] > TQ:

// Advance time by full quantum: time = time + TQ

// Decrease remaining time: Rem[i] = Rem[i] - TQ

// Step 4: Handle CPU Idle Time

// If after scanning all processes, the flag progressed is still 0 (meaning no uncompleted process has arrived by the current time), the CPU is idle.

// Increment time by 1: time++.

// Step 5: Calculate Turnaround and Waiting Times

// Initialize totalTAT = 0 and totalWT = 0.

// Loop through all n processes:

// Calculate Turnaround Time: TAT[i] = CT[i] - AT[i]

// Calculate Waiting Time: WT[i] = TAT[i] - BT[i]

// Add to totals:

// totalTAT = totalTAT + TAT[i]

// totalWT = totalWT + WT[i]

// Step 6: Display Results and Stop

// Calculate Average Turnaround Time = totalTAT / n.

// Calculate Average Waiting Time = totalWT / n.

// Print the averages and terminate the algorithm.