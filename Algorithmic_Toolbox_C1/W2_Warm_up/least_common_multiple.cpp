/*
 ============================================================================
 Name        : least_common_multiple.cpp
 Author      : Ivan Arevalo
 Version     :
 Copyright   : Your copyright notice3
 Description : Compute LCM
 ============================================================================
 */

#include <iostream>
#include <cassert>
#include <cstdlib> 
#include <ctime>
#include <cmath>

#define CHAR_BUFFSIZE (int) (1<<20) // 2^20 = 1048576 bytes around 1 mb


// Naive implementation, tests all numbers between 2 and the smallest of the 2 numbers.

long lcm_naive(int a, int b){
    long current_lcd = (long) a*b;
    for(long d = a*b; d >= fmax(a,b) ; --d){
    	if(d % a == 0 && d % b == 0 && d < current_lcd)
    		current_lcd = d;
    }
    return current_lcd;
}


long lcm_eff(int a, int b) {
	long lcm = (long) a * b;
	int temp;
	while(b != 0){
		temp = a;
		a = b;
		b = temp % b;
	}
	return lcm / a;
}


void stress_test(int max_n) {

	int counter = 0;
	int a;
	int b;
	srand(time(0));

	while(1){
		a = rand() % max_n; a++;
		b = rand() % max_n; b++;

		long sol1 = lcm_naive(a, b);
		long sol2 = lcm_eff(a, b);

		assert(sol1 == sol2);
		printf("Test %d successful\n", counter);
		counter++;
	}
}

int main() {
	char debug = 0;

	if(debug){
		stress_test(10000);
	}else{
		int a = 0;
		int b = 0;
	    std::cin >> a;
	    std::cin >> b;

	    // std::cout << lcm_naive(a, b) << '\n';
	    std::cout << lcm_eff(a, b) << '\n';
	}

    
    return 0;
}
