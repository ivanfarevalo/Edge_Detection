/*
 ============================================================================
 Name        : least_common_multiple.c
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
#include <math.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
// Naive implementation, tests all numbers between 2 and the smallest of the 2 numbers.

int lcm_naive(int a, int b){
    int current_lcm = a*b;
    for(int d = 2; d <= a*b; ++d){
    	if(d % a == 0 && d % b == 0 && d < current_lcm)
    		current_lcm = d;
    }

    return current_lcm;
}

// Euclidean algorithm implementation: GCD(a, b) = GCD(b, a%b)
long lcm_euclidean(long a, long b){
    long gcm = a*b;
	long temp;
    while(b != 0){
    	temp = a;
    	a = b;
    	b = temp % b;
    }

    return (long) gcm/a;
}


int stress_test(void){

	int counter = 0;
	int n;
	srand(time(0));
    
    while(1){
		int a = (rand() % 2000) + 1;
        int b = (rand() % 2000) + 1;

        int sol1 = lcm_naive(a, b);
        int sol2 = lcm_euclidean(a, b);

        int n = 10;
		char *msg;
		asprintf(&msg, "ERROR: %d\n SOL1: %d\nSOL2: %d", n, sol1, sol2);
        
        assert(sol1 == sol2 && *msg);
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
		long a;
        long b;
		scanf("%ld %ld", &a, &b);
        // printf("%d\n", MIN(a,b));
		// printf("%d\n", lcm_naive(a, b));
		printf("%ld\n", lcm_euclidean(a, b));
	}
	
	return 0;
}


