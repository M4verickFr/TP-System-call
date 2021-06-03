#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv){
    int pid = fork();
    int status;
    if(pid==0){
        int random = rand() % 20;
        printf("child(%d) return %d\n",getpid(), random);
        return random;
    }else{
        waitpid(pid, &status, 0);
        printf("Parent(%d) get %d from child\n", getpid(), WEXITSTATUS(status));  
    }
    sleep(3);
	return 0;
}