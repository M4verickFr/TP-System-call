#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv){
	int n = atoi(argv[1]);
    
    while(n>0) {
        n--;
        int pid = fork();

        printf("PID : %d\n",pid);

        if(pid){
            wait(NULL);
        }else{
            sleep(10);
        }
	}
    sleep(3);
	return 0;
}