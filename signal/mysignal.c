#include <stdio.h>

#define MY_SIGNAL 2
#define MAX_SIGNAL 32
#define SIG_DDD_X (void (*) ()) -1
#define SIG_DDD_Y (void (*) ()) 0
#define SIG_DDD_Z (void (*) ()) +1
typedef void Sigfunc(int);
Sigfunc *signal_tak(int, Sigfunc *);

struct{
	int signo;
	Sigfunc* signal_handler;
}sigtab[MAX_SIGNAL];

Sigfunc* signal_tak(int signo, Sigfunc* my_signal){
	sigtab[signo].signo = signo;
	sigtab[signo].signal_handler = my_signal;

	return SIG_DDD_Z;
}
void sig_usr(int signo){
	printf("A signal [%d] occurs\n", signo);
}

int main(void){
	int signo;
	if(signal_tak(MY_SIGNAL, sig_usr) == SIG_DDD_Z){
		printf("Return 1\n");
	}
	//kernel cathc my_signal	
	signo = MY_SIGNAL;	
	//Run the handler for MY_SIGNAL
	sigtab[MY_SIGNAL].signal_handler(signo);
}
