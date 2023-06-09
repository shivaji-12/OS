#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char message[] = "Hello, child process!";

    // Create a pipe
    pipe(pipefd);

    // Fork a child process
    if (fork() == 0) {
        // Child process

        // Close the write end of the pipe
        close(pipefd[1]);

        // Read data from the pipe
        char buffer[50];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received message: %s\n", buffer);

        // Close the read end of the pipe
        close(pipefd[0]);
    } else {
        // Parent process

        // Close the read end of the pipe
        close(pipefd[0]);

        // Write data to the pipe
        write(pipefd[1], message, sizeof(message));

        // Close the write end of the pipe
        close(pipefd[1]);
    }

    return 0;
}

