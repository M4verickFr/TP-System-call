#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int children = n;
    
    while (n>0) {
        n--;
        int pid = 0;
        for (int compteur = 0 ; compteur < children ; compteur++)
        {
            pid = fork();
            if (pid == 0) {
                break;
            }
        }
        if (pid) {
            break;
        }
    }
    
    if (n == children-1) {
        char pid[10];
        sprintf(pid, "%d", getpid());
        execl("/bin/pstree", "pstree", "-c", pid, (char*)0);
    }
    printf("n: %d | PID: %d | PPID: %d | Children: %d\n", n, getpid(), getppid(), children);
    sleep(2);
    return 0;
}

