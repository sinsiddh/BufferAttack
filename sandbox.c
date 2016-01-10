#include<stdio.h>
#include <signal.h>
#include <unistd.h>
#include<string.h>
#include <stdlib.h>
#include<sys/mman.h>
#include<sys/ucontext.h>

long int ret_addr;

void sig_segv_handler(int sig, siginfo_t *sip, ucontext_t *context) {
        if ( (long int)(sip->si_addr) == 0x0000000000401798) {
                ret_addr = *(long int *)context->uc_mcontext.gregs[15];
		mprotect((void*)(0x0000000000401798 & 0xfffffffffffff000), 4096 ,PROT_READ | PROT_WRITE | PROT_EXEC);
		mprotect((void*)(0x000000000040281c & 0xfffffffffffff000 ), 4096 , PROT_READ | PROT_WRITE);
        } else if ((long int)(sip->si_addr) == ret_addr) {
	        mprotect((void*)(0x000000000040281c & 0xfffffffffffff000 ), 4096 , PROT_READ | PROT_WRITE | PROT_EXEC);	
		mprotect((void*)(0x0000000000401798 & 0xfffffffffffff000), 4096 , PROT_READ | PROT_WRITE);
	} else {
		printf("malicious buffer overflow detected, will exit!\n");
                exit(0);
        }
}


void init_sandbox (void) {
    char c;
    struct sigaction action;
    action.sa_flags = SA_SIGINFO | SA_RESTART;
    action.sa_sigaction = sig_segv_handler;
    sigfillset (&action.sa_mask);
    sigaction(SIGSEGV,&action,NULL);
	//Main
    if((mprotect((void*)(0x000000000040281c & 0xfffffffffffff000 ), 4096 , PROT_READ | PROT_WRITE | PROT_EXEC)) == -1 ) {
	printf("Couldn't mprotect main\n");
	exit(0);
    }
    //ReadString
    if (mprotect((void*)(0x0000000000401798 & 0xfffffffffffff000 ), 4096 , PROT_READ | PROT_WRITE)) {
        printf("Couldn't mprotect Readstr\n");
	exit(0);
    }
    //Signal Handler
    if (mprotect((void*)(0x0000000000403a1b & 0xfffffffffffff000 ), 4096 , PROT_EXEC)) {
        printf("Couldn't mprotect SigHandler\n");
	exit(0);
    }
}
