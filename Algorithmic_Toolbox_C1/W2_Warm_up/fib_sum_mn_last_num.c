/*
 ============================================================================
 Name        : fib_sum_mn_last_num.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Compute nth fibonacci number mod m Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define CHAR_BUFFSIZE (int) (1<<20) // 2^20 = 1048576 bytes around 1 mb

int get_fib_sum_last_num_naive(long m, long n) {
	if(n <= 1)
		return n;

	int past = 0;
	int current = 1;
	int temp;
	int sum;
	if(m >= 2){
		sum = 0;
	}else{
		sum = 1;
	}


	for(long i = 2; i <= n; ++i) {
		temp = past;
		past = current;
		current = (current + temp) % 10;

		if(i >= m)
			sum = (sum + current) % 10;
	}

	return sum;
}

char get_fib_sum_last_num_eff(long m, long n){


	char fib_sum[CHAR_BUFFSIZE+1]; fib_sum[0] = 0; fib_sum[1] = 1;
	
	if(n <= 1)
		return (char) n;

	for(long i = 2; i <= n; ++i) {

		fib_sum[i] = (1 + fib_sum[i-1] + fib_sum[i-2]) % 10;

		if(fib_sum[i-1] == 0 && fib_sum[i] == 1){
			if(m == 0){
				return fib_sum[n % (i-1)];
			}else{
			return (10 + ( ( fib_sum[n % (i-1)] - fib_sum[(m-1)%(i-1)] ) % 10 ) ) % 10;
			}
		}
		if(i % CHAR_BUFFSIZE == 0){
			printf("Pisano period is too large or non-existent\n");
			return 0;
		}
	}

	if(m==0){
		return fib_sum[n];
	}else{
		return (10 + ((fib_sum[n] - fib_sum[m-1])%10)) % 10;
	}
}


int stress_test(long max_n){

	long counter = 0;
	long n;
	long m;
	srand(time(0));
    
    while(1){
    	n = rand() % max_n; n++;
    	m = rand() % n; m++;

        int sol1 = get_fib_sum_last_num_naive(m, n);
        int sol2 = get_fib_sum_last_num_eff(m, n);

		char *msg;
		asprintf(&msg, "ERROR: m = %ld n = %ld\n SOL1: %d\nSOL2: %d", m, n, sol1, sol2);
        
        assert(sol1 == sol2 && msg);
        free(msg); // release the memory allocated by asprintf.

        printf("Test %ld successful\n", counter);
        counter = counter + 1;
    }
}

int main(void) {
	int debug = 0;

	if(debug == 1){
		stress_test(5000);
	}
	else{
		long m;
		long n;
		scanf("%ld %ld", &m, &n);
		// printf("%d\n", get_fib_sum_last_num_naive(m, n));
		printf("%d\n", get_fib_sum_last_num_eff(m, n));
	}

	
	return 0;
}
