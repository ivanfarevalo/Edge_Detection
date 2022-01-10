/*
 ============================================================================
 Name        : money_change.cpp
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Compute minimum number of coins to represent monetary value Ansi-style
 ============================================================================
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>

// #define CHAR_BUFFSIZE (int) (1<<20) // 2^20 = 1048576 bytes around 1 mb

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

		// string msg;
		// asprintf(msg, "ERROR: %d\n SOL1: %d\nSOL2: %d", n, sol1, sol2);
        


        assert(sol1 == sol2);
        // free(msg); // release the memory allocated by asprintf.

        std::cout << "Test " << counter << " successful" << endl;
        // printf("Test %d successful\n", counter);
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

		std::cin >> n;;
		std::cout << get_change_eff(n);
	}

	
	return 0;
}
