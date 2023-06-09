#include <stdio.h>
#include <stdlib.h>

#define TOTAL_REQUESTS 8 // Total number of disk requests

void calculateSeekTime(int initialPosition, int requests[]) {
    int current = initialPosition;
    int totalSeekTime = 0;
    int completed[TOTAL_REQUESTS] = {0}; // Array to keep track of completed requests

    printf("Disk Head Movement:\n");
    printf("%d -> ", current);

    for (int i = 0; i < TOTAL_REQUESTS; i++) {
        int minDistance = 9999; // Initialize with a large value
        int minIndex = -1;

        // Find the request with the shortest seek time
        for (int j = 0; j < TOTAL_REQUESTS; j++) {
            if (!completed[j]) {
                int distance = abs(requests[j] - current);
                if (distance < minDistance) {
                    minDistance = distance;
                    minIndex = j;
                }
            }
        }

        // Mark the selected request as completed
        completed[minIndex] = 1;
        current = requests[minIndex];
        totalSeekTime += minDistance;

        printf("%d -> ", current);
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);
}

int main() {
    int initialPosition = 50; // Initial position of the disk head
    int requests[TOTAL_REQUESTS] = { 98, 183, 37, 122, 14, 124, 65, 67 }; // Disk requests

    calculateSeekTime(initialPosition, requests);

    return 0;
}

