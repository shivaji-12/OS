#include <stdio.h>

void sjf(int burst_time[], int n) {
    int waiting_time = 0, total_waiting_time = 0;
    int turnaround_time, total_turnaround_time = 0;
    int smallest, temp;

    // Sort the burst times in ascending order using the Selection Sort algorithm
    for (int i = 0; i < n; i++) {
        smallest = i;
        for (int j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[smallest]) {
                smallest = j;
            }
        }
        // Swap burst times
        temp = burst_time[i];
        burst_time[i] = burst_time[smallest];
        burst_time[smallest] = temp;

        // Calculate waiting time and turnaround time for the current process
        waiting_time += burst_time[i - 1];
        turnaround_time = burst_time[i] + waiting_time;

        // Accumulate total waiting time and total turnaround time
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;

        // Print scheduling results for the current process
        printf("Process %d:\tBurst Time: %d\tWaiting Time: %d\tTurnaround Time: %d\n",
               i + 1, burst_time[i], waiting_time, turnaround_time);
    }
    printf("%d",n);
    // Calculate average waiting time and average turnaround time
    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;

    // Print average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}

int main() {
    // Burst times of the processes
    int burst_time[] = {10, 4, 7, 3, 5};
    int n = sizeof(burst_time) / sizeof(burst_time[0]);
    
    // Call the SJF function
    sjf(burst_time, n);

    return 0;
}

