#include <stdio.h>
#include <stdlib.h>

#define TOTAL_REQUESTS 8 // Total number of disk requests
#define MAX_CYLINDER 199 // Maximum cylinder value

void calculateSeekTime(int initialPosition, int requests[]) {
    int current = initialPosition;
    int totalSeekTime = 0;
    int direction = 1; // 1 for moving towards higher cylinder numbers, -1 for moving towards lower cylinder numbers

    printf("Disk Head Movement:\n");
    printf("%d -> ", current);

    while (1) {
        int found = 0;

        // Scan requests in the current direction
        for (int i = 0; i < TOTAL_REQUESTS; i++) {
            if (requests[i] == current) {
                found = 1;
                requests[i] = -1; // Mark the request as completed
                totalSeekTime += abs(current - initialPosition);
                printf("%d -> ", current);
                break;
            }
        }

        // Change direction if no requests are found in the current direction
        if (!found) {
            if (direction == 1 && current == MAX_CYLINDER) {
                direction = -1;
                printf("%d -> ", current); // Stay at the current position
            } else if (direction == -1 && current == 0) {
                direction = 1;
                printf("%d -> ", current); // Stay at the current position
            } else {
                current += direction;
                printf("%d -> ", current); // Move to the next cylinder
                totalSeekTime++;
            }
        } else {
            current += direction;
        }

        // Exit the loop if all requests have been processed
        int allCompleted = 1;
        for (int i = 0; i < TOTAL_REQUESTS; i++) {
            if (requests[i] != -1) {
                allCompleted = 0;
                break;
            }
        }
        if (allCompleted) {
            break;
        }
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);
}

int main() {
    int initialPosition = 50; // Initial position of the disk head
    int requests[TOTAL_REQUESTS] = { 98, 183, 37, 122, 14, 124, 65, 67 }; // Disk requests

    calculateSeekTime(initialPosition, requests);

    return 0;
}

