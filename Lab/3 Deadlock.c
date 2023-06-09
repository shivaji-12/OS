#include <stdio.h>

int main() {
    int resource1 = 1;
    int resource2 = 1;

    // Process 1 requests resource 1
    if (resource1 == 1) {
        resource1 = 0; // Allocate resource 1
        printf("Process 1 has acquired resource 1.\n");

        // Process 2 requests resource 2
        if (resource2 == 1) {
            resource2 = 0; // Allocate resource 2
            printf("Process 2 has acquired resource 2.\n");
        }
    }

    // Process 1 requests resource 2
    if (resource2 == 1) {
        resource2 = 0; // Allocate resource 2
        printf("Process 1 Acquires resource 2.\n");
    }
else if (resource2 ==0)
{   
printf("Process 1 wants resource 2.\n");
}


    // Process 2 requests resource 1
    if (resource1 == 1) {
        resource1 = 0; // Allocate resource 1
        printf("Process 2 Acquires resource 1.\n");
    }
else if (resource1 ==0)
{   
printf("Process 2 wants resource 1.\n");
}

    printf("Deadlock has occurred. Both processes are waiting indefinitely.\n");
    return 0;
}

