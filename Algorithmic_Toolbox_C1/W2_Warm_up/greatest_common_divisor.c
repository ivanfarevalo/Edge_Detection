/*
 ============================================================================
 Name        : greatest_common_divisor.c
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

int gcd_naive(int a, int b){
    int current_gcd = 1;
    for(int d = 2; d <= MIN(a,b); ++d){
    	if(a % d == 0 && b % d == 0 && d > current_gcd)
    		current_gcd = d;
    }

    return current_gcd;
}

// Euclidean algorithm implementation: GCD(a, b) = GCD(b, a%b)
int gcd_euclidean(int a, int b){
	int temp;
    while(b != 0){
    	temp = a;
    	a = b;
    	b = temp % b;
    }

    return a;
}


int stress_test(void){

	int counter = 0;
	int n;
	srand(time(0));
    
    while(1){
		int a = (rand() % 2000000) + 1;
        int b = (rand() % 2000000) + 1;

        int sol1 = gcd_naive(a, b);
        int sol2 = gcd_euclidean(a, b);

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
		int a;
        int b;
		scanf("%d %d", &a, &b);
        // printf("%d\n", MIN(a,b));
		// printf("%d\n", gcd_naive(a, b));
		printf("%d\n", gcd_euclidean(a, b));
	}

	
	return 0;
}


