#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: \n");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n], done[n];

    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority for P%d: \n", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        done[i] = 0;
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        // Find process with highest priority (lowest value) among arrived and not done
        int idx = -1;
        int min_pr = 99999;

        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= current_time) {
                if (pr[i] < min_pr) {
                    min_pr = pr[i];
                    idx = i;
                } else if (pr[i] == min_pr && at[i] < at[idx]) {
                    // Tie-break: earlier arrival time wins
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process has arrived yet, advance time
            current_time++;
            continue;
        }

        // Execute selected process
        current_time += bt[idx];
        ct[idx] = current_time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    printf("Average Waiting Time = %.2f\n", totalWT / n);

    return 0;
}

// Step 1: Start and Initialize

// Read the total number of processes, n

// For each process, input its Arrival Time (AT), Burst Time (BT), and Priority (PR).

// Create an array called Done of size n and set all its values to 0 (False) to track which processes have finished.

// Initialize current_time = 0 and completed_processes = 0.

// Step 2: Process Execution Loop
// Repeat Steps 3 to 5 while completed_processes < n:

// Step 3: Find the Highest Priority Available Job

// Search through all n processes to find the one that meets these conditions:

// Has already arrived (AT[i] <= current_time)

// Has not been executed yet (Done[i] == 0)

// Has the highest priority (which means the minimum PR value) among all available processes.

// Tie-breaker condition: If two or more available processes have the exact same priority value, select the one with the earliest Arrival Time (AT).

// Let the index of this selected process be idx.

// Step 4: Handle CPU Idle Time

// If no process is found in Step 3 (idx == -1), it means no uncompleted process has arrived by the current_time. The CPU is idle.

// Increment current_time by 1 (current_time++) and go back to Step 3.

// Step 5: Execute the Selected Process

// If a process idx was found:

// The process runs to completion (non-preemptive). Advance the current time by adding the process's burst time:
// current_time = current_time + BT[idx]

// Calculate Completion Time: CT[idx] = current_time

// Calculate Turnaround Time: TAT[idx] = CT[idx] - AT[idx]

// Calculate Waiting Time: WT[idx] = TAT[idx] - BT[idx]

// Mark the process as finished: Done[idx] = 1

// Increment completed_processes by 1.

// Step 6: Calculate Averages

// Initialize totalTAT = 0 and totalWT = 0.

// Loop through all n processes to add up their individual TAT and WT.

// Calculate Average Turnaround Time = totalTAT / n

// Calculate Average Waiting Time = totalWT / n

// Step 7: Display Results and Stop

// Print the calculated Average Turnaround Time and Average Waiting Time.

// Terminate the algorithm.