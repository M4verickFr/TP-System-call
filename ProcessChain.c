#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int pid = 0;
    
    while (n>0) {
        n--;
        int pid = fork();
        if (pid) {
            break;
        }
    }
    
    printf("n: %d | PID: %d | PPID: %d\n", n, getpid(), getppid());
    sleep(2);
    return 0;
}

