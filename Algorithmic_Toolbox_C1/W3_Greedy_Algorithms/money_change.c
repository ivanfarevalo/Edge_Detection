/*
 ============================================================================
 Name        : money_change.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Compute minimum number of coins to represent monetary value Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define CHAR_BUFFSIZE (int) (1<<20) // 2^20 = 1048576 bytes around 1 mb

int get_change_naive(int n) {
	
	int num_coins = 0;

	while(n > 0){

		if(n >= 10){
			num_coins = num_coins + (n / 10);
			n = n % 10;
		}
		else if(n >= 5){
			num_coins = num_coins + (n / 5);
			n = n % 5;
		}
		else{
			num_coins = num_coins + n;
			n = 0;
		}
	}

	return num_coins;
}

char get_change_eff(int n){
	return (n/10) + (n%10)/5 + (n%5);
}


int stress_test(int max_n){

	int counter = 0;
	int n;
	srand(time(0));
    
    while(1){
		n = rand() % max_n; n++;

        int sol1 = get_change_naive(n);
        int sol2 = get_change_eff(n);

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
		stress_test(1000);
	}
	else{
		int n;
		scanf("%d", &n);
		// printf("%d\n", get_fib_sum_last_num_naive(n));
		printf("%d\n", get_change_eff(n));
	}

	
	return 0;
}
