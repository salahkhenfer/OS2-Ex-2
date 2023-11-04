#include <stdio.h>
#include <unistd.h>

int main() {
    int levels ; // Number of levels in the process tree
    
    printf("enter the number of levels : ");
    scanf("%d",&levels);
    int currentLevel;

    for (currentLevel = 0; currentLevel < levels; currentLevel++) {
        pid_t child_pid = fork();

        if (child_pid == 0) {
            // This code is executed by the child process
            printf("Child Process (Level %d): PID = %d\n", currentLevel, getpid());
        } else if (child_pid > 0) {
            // This code is executed by the parent process
            printf("Parent Process (Level %d): PID = %d\n", currentLevel, getpid());
            // The parent waits for the child to finish its execution
 
        } else {
            // Error occurred during fork()
            fprintf(stderr, "Fork failed\n");
            return 1;
        }
    }

    // Allow some time for processes to finish before exiting
    if (currentLevel == 0) {
        sleep(5);
    }

    return 0;
}
