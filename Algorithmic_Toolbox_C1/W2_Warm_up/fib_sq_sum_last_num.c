/*
 ============================================================================
 Name        : fib_sq_sum_last_num.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice3
 Description : Compute nth fibonacci number mod m Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define CHAR_BUFFSIZE (int) (1<<20) // 2^20 = 1048576 bytes around 1 mb

int get_fib_sum_last_num_naive(long n) {
	if(n <= 1) {
		return n;
	}
	int past = 0;
	int current = 1;
	int temp;
	int sum = past + current;
	int prod;


	for(long i = 2; i <= n; ++i) {
		temp = past;
		past = current;
		current = (current + temp) % 10;
		sum = (sum + current) % 10;
	}

	return (current * (current + past)) % 10;
}

char get_fib_sum_last_num_eff(long n){


	char fib_num[CHAR_BUFFSIZE+1]; fib_num[0] = 0; fib_num[1] = 1;
	
	if(n <= 1)
		return (char) n;

	for(long i = 2; i <= n; ++i) {

		fib_num[i] = (fib_num[i-1] + fib_num[i-2]) % 10;

		if(fib_num[i-1] == 0 && fib_num[i] == 1)
			return (fib_num[n%(i-1)] * (fib_num[n%(i-1)] + fib_num[(n-1)%(i-1)])) % 10;

		if(i % CHAR_BUFFSIZE == 0){
			printf("Pisano period is too large or non-existent\n");
			return 0;
		}
	}

	return (fib_num[n] * (fib_num[n]+fib_num[n-1]) ) % 10;
}


int stress_test(int max_n){

	int counter = 0;
	int n;
	srand(time(0));
    
    while(1){
		n = rand() % max_n; n++;

        int sol1 = get_fib_sum_last_num_naive(n);
        int sol2 = get_fib_sum_last_num_eff(n);

		char *msg;
		asprintf(&msg, "ERROR: %d\n SOL1: %d\nSOL2: %d", n, sol1, sol2);
        
        assert(sol1 == sol2 && msg);
        free(msg); // release the memory allocated by asprintf.

        printf("Test %d successful\n", counter);
        counter = counter + 1;
    }
}

int main(void) {
	int debug = 0;

	if(debug == 1){
		stress_test(50000);
	}
	else{
		long n;
		scanf("%ld", &n);
		// printf("%d\n", get_fib_sum_last_num_naive(n));
		printf("%d\n", get_fib_sum_last_num_eff(n));
	}

	
	return 0;
}
