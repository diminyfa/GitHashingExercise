#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int sig){
	printf("\n SIGINT signal caught! Exiting...\n");
	exit(0);
}

int main(){
	
	signal(SIGINT, sigint_handler);

	while(1){
		printf("Running... Press Ctrl+C to exit.\n");
		sleep(2);
	}

	return 0;
}
