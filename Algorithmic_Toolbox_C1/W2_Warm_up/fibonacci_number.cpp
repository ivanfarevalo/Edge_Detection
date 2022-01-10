/*
 ============================================================================
 Name        : fibonacci_number.cpp
 Author      : Ivan Arevalo
 Version     :
 Copyright   : Your copyright notice3
 Description : Compute nth fibonacci number
 ============================================================================
 */

#include <iostream>
#include <cassert>
#include <cstdlib> 
#include <ctime>


long fib_naive(int n) {
    if (n <= 1)
        return n;

    return fib_naive(n - 1) + fib_naive(n - 2);
}

long fib_eff(int n) {

	if (n <= 1)
        return n;
    
    long past = 0;
    long current = 1;
    long temp;

    for(int i = 2; i <= n; ++i){

    	temp = past;
    	past = current;
    	current = current + temp;

    }
    return current;

}

void stress_test(int max_n) {

	long counter = 0;
	int n;
	srand(time(0));

	while(1){
		n = rand() % max_n; n++;
		long sol1 = fib_naive(n);
		long sol2 = fib_eff(n);

		assert(sol1 == sol2);
		printf("Test %ld successful\n", counter);
		counter++;

	}

}

int main() {
	int debug = 0;

	if(debug){
		stress_test(25);
	}else{
		int n = 0;
	    std::cin >> n;

	    // std::cout << fib_naive(n) << '\n';
	    std::cout << fib_eff(n) << '\n';
	}

    
    return 0;
}
