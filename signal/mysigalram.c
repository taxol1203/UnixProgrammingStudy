#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int counter = 0;
int myInterrupt = 0;
void mysignalHandler(int signo){

	printf("Alarm %d [signal number : %d]\n", counter++, signo);
	alarm(2);
}
void mysignalHandler2(int signo){

	printf("My Interrupt %d [signal number : %d]\n", myInterrupt++, signo);
}
int main(void){

	//Register SiGALARM
	signal(SIGALRM, mysignalHandler);
	signal(SIGINT, mysignalHandler2);
	alarm(2);

	//I want to trigger SIGALM forever
	while(1);

	return 0;
}
