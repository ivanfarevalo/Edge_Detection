/*
 ============================================================================
 Name        : greatest_common_divisor.cpp
 Author      : Ivan Arevalo
 Version     :
 Copyright   : Your copyright notice3
 Description : Compute GCD
 ============================================================================
 */

#include <iostream>
#include <cassert>
#include <cstdlib> 
#include <ctime>
#include <cmath>

#define CHAR_BUFFSIZE (int) (1<<20) // 2^20 = 1048576 bytes around 1 mb


// Naive implementation, tests all numbers between 2 and the smallest of the 2 numbers.

int gcd_naive(int a, int b){
    int current_gcd = 1;
    for(int d = 2; d <= fmin(a,b); ++d){
    	if(a % d == 0 && b % d == 0 && d > current_gcd)
    		current_gcd = d;
    }

    return current_gcd;
}

int gcd_eff(int a, int b) {
	int temp;
	while(b != 0){
		temp = a;
		a = b;
		b = temp % b;
	}

	return a;
}


void stress_test(int max_n) {

	int counter = 0;
	int a;
	int b;
	srand(time(0));

	while(1){
		a = rand() % max_n; a++;
		b = rand() % max_n; b++;

		int sol1 = gcd_naive(a, b);
		int sol2 = gcd_eff(a, b);

		assert(sol1 == sol2);
		printf("Test %d successful\n", counter);
		counter++;
	}
}

int main() {
	char debug = 0;

	if(debug){
		stress_test(1000);
	}else{
		int a = 0;
		int b = 0;
	    std::cin >> a;
	    std::cin >> b;

	    // std::cout << gcd_naive(a, b) << '\n';
	    std::cout << gcd_eff(a, b) << '\n';
	}

    
    return 0;
}
