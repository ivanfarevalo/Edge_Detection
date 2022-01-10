/*
 ============================================================================
 Name        : fibonacci_remainder.c
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

struct Large_Num {
	char num[100];

};

struct Large_Num add(struct Large_Num num1, struct Large_Num num2){
	struct Large_Num result;
	char carry_over = 0;
	for(int i = 0; i<=1; ++i){
		result.num[i] = (num1.num[i] + num2.num[i] + carry_over) % 10;
		carry_over = (num1.num[i] + num2.num[i]) / 10 ;
// 		printf("%d", result.num[i]);
	}
	return result;
}

void print_large_num(struct Large_Num number, int num_length){
    for(int i = num_length-1; i>-1; --i){
		printf("%d", number.num[i]);
	}
}

long get_fibonacci_remainder_naive(long n, long m) {
	if(n <= 1) {
		return n;
	}
	long past = 0;
	long current = 1;
	long temp;

	for(int i = 2; i <= n; ++i) {
		temp = past;
		past = current;
		current = current + temp;
	}

	return current % m;
}

int get_fibonacci_remainder_mem_eff(long n, int m){
	// unsigned long fib_table[CHAR_BUFFSIZE/8]; fib_table[0] = 0; fib_table[1] = 1;

	struct Large_Num past; past.num[0] = 0;
	struct Large_Num current; past.num[1] = 1;
	struct Large_Num temp;

	int pisano_table[CHAR_BUFFSIZE+1]; pisano_table[0] = 0; pisano_table[1] = 1;
	if(n <= 1)
		return n;
	int i;

	printf("%d %d ", pisano_table[0], pisano_table[1]); // Debug

	for(i = 2; i <= n+1; ++i) {
		// fib_table[i] = fib_table[i-1] + fib_table[i-2];

		temp = past;
		past = current;
		current = add(current, temp);

		pisano_table[i] = fib_table[i] % m; // Need to implement modulus operator
		printf("%d ", pisano_table[i]); // Debug
		if(pisano_table[i-1] == 0 && pisano_table[i] ==1){
			printf("\nPisano period found at i: %d\n", i); // Debug
			// printf("%d %d %d\n", pisano_table[n % (i-2)], pisano_table[n % (i-1)], pisano_table[n % (i)]);
			printf("%d %d %d\n", pisano_table[(i-2)], pisano_table[(i-1)], pisano_table[(i)]); // Debug
			return pisano_table[n % (i-1)];

		}

	}

	printf("\n");
	printf("%lu\n", fib_table[n]);
	// printf("%d %d %d\n", pisano_table[(i-2)], pisano_table[(i-1)], pisano_table[(i)]);
			

	return pisano_table[n];
}

int stress_test(void){

	int counter = 0;
	int n;
	int m;
	srand(time(0));
    
    while(1){
		n = rand() % 25; n++;
		m = rand() % 20; m++;

        int sol1 = get_fibonacci_remainder_naive(n, m);
        int sol2 = get_fibonacci_remainder_mem_eff(n, m);

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
		long n;
		int m;
		scanf("%ld %d", &n, &m);
		// printf("%d\n", get_fibonacci_remainder_naive(n, m));

		printf("%d\n", get_fibonacci_remainder_mem_eff(n, m));
	}

	
	return 0;
}
