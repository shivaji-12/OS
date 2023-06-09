#include <stdio.h>

void fcfs(int burst_time[], int n) {
    int waiting_time = 0, total_waiting_time = 0;
    int turnaround_time, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time;
        turnaround_time = burst_time[i] + waiting_time;
        total_turnaround_time += turnaround_time;
        waiting_time += burst_time[i];
        printf("Process %d:\tBurst Time: %d\tWaiting Time: %d\tTurnaround Time: %d\n",
               i + 1, burst_time[i], waiting_time - burst_time[i], turnaround_time);
    }

    double avg_waiting_time = (double) total_waiting_time / n;
    double avg_turnaround_time = (double) total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}

int main() {
    int burst_time[5] = {10, 4, 7, 3, 5};
    int n = 5

    fcfs(burst_time, n);

    return 0;
}

