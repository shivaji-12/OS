#include <stdio.h>
#include <stdlib.h>

#define TOTAL_REQUESTS 8 // Total number of disk requests

void calculateSeekTime(int initialPosition, int requests[]) {
    int current = initialPosition;
    int totalSeekTime = 0;

    printf("Disk Head Movement:\n");
    printf("%d -> ", current);

    for (int i = 0; i < TOTAL_REQUESTS; i++) {
        int distance = abs(requests[i] - current);
        totalSeekTime += distance;
        current = requests[i];

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

