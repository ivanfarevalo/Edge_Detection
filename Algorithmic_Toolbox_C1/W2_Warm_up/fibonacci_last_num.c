/*
 ============================================================================
 Name        : fibonacci_last_num.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Compute last number of nth fibonacci number, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int get_fibonacci_last_digit_naive(int n) {
	if(n <= 1) {
		return n;
	}
	int past = 0;
	int current = 1;
	int temp;

	for(int i = 2; i <= n; ++i) {
		temp = past;
		past = current;
		current = current + temp;
	}

	return current % 10;
}

int get_fibonacci_last_digit_eff(int n) {
	if(n <= 1) {
		return n;
	}
	int past = 0;
	int current = 1;
	int temp;

	for(int i = 2; i <= n; ++i) {
		temp = past;
		past = current;
		current = (current + temp)%10;
	}

	return current;
}

int stress_test(void){

	int counter = 0;
	int n;
	srand(time(0));
    
    while(1){
		n = rand() % 25;

        int sol1 = get_fibonacci_last_digit_naive(n);
        int sol2 = get_fibonacci_last_digit_eff(n);

        int n = 10;
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
		stress_test();
	}
	else{
		int n;
		scanf("%d", &n);
		// printf("%d\n", get_fibonacci_last_digit_naive(n));
		printf("%d\n", get_fibonacci_last_digit_eff(n));
	}

	
	return 0;
}


