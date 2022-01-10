/*
 ============================================================================
 Name        : fibonacci_last_num.cpp
 Author      : Ivan Arevalo
 Version     :
 Copyright   : Your copyright notice3
 Description : Compute last nth fibonacci number
 ============================================================================
 */

#include <iostream>
#include <cassert>
#include <cstdlib> 
#include <ctime>

#define CHAR_BUFFSIZE (int) (1<<20) // 2^20 = 1048576 bytes around 1 mb


char fib_naive(int n) {
    if (n <= 1)
        return n;
    
    char past = 0;
    char current = 1;
    char temp;

    for(int i = 2; i <= n; ++i){

    	temp = past;
    	past = current;
    	current = (current + temp) % 10;

    }
    return current;
}

char fib_eff(int n) {
	if (n <= 1)
        return n;

    char fib_num[CHAR_BUFFSIZE+1]; fib_num[0] =  0; fib_num[1] = 1;

    for(int i = 2; i <= n; ++i){
    	fib_num[i] = (fib_num[i-1] + fib_num[i-2]) % 10;

    	if(fib_num[i-1] == 0 && fib_num[i] == 1){
    		return fib_num[n % (i-1)];
    	}

    }

    return fib_num[n];
}


void stress_test(int max_n) {

	int counter = 0;
	int n;
	srand(time(0));

	while(1){
		n = rand() % max_n; n++;
		char sol1 = fib_naive(n);
		char sol2 = fib_eff(n);

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
		int n = 0;
	    std::cin >> n;

	    // std::cout << (int) fib_naive(n) << '\n';
	    std::cout << (int) fib_eff(n) << '\n';
	}

    
    return 0;
}
