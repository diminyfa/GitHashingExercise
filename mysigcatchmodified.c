#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int sigint_count = 0;

void custom_sigint_handler(int sig){
	sigint_count++;
        printf("\n caught SIGINT signal: %d \n", sig);

	if (sigint_count == 2){
		signal(SIGINT, SIG_DFL);
		exit(0);
	}
}

int main(){

        signal(SIGINT, custom_sigint_handler);

        while(1){
                printf("Running... Press Ctrl+C to exit.\n");
                sleep(2);
        }

        return 0;
}


