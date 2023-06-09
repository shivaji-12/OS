#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        // This code is executed by the child process

        printf("Child process is running. Process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
    } else {
        // This code is executed by the parent process

        printf("Parent process is running. Process ID: %d\n", getpid());
        printf("Child process ID: %d\n", pid);
    }

    return 0;
}

