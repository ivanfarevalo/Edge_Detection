/*
 ============================================================================
 Name        : knapsack.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Find max value of loot you can get Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


void remove_item(int size, int index, int array[]){
	assert(index < size);
	for(int i = index; i < size-1; ++i){
		array[i] = array[i+1];
	}
}


double get_max_value(int n, int w, int value[], int weight[]) {
	
	double total_value = 0.0;

	while(w > 0 && n > 0){

		int max_i = 0;

		for(int i = 0; i < n; ++i){

			if( (double) value[i]/weight[i] > (double) value[max_i]/weight[max_i] ) {
				max_i = i;
			}
		}

		if(weight[max_i] < w){
			total_value += (double) value[max_i];
			w -= weight[max_i];
		}else{

			total_value += (double) value[max_i] / weight[max_i] * w ;
			w = 0;
		}
		
		remove_item(n, max_i, value);
		remove_item(n, max_i, weight);
		n--;


	}

	return total_value;
}


int main(void) {

	int n, w;
	scanf("%d %d", &n, &w);
	assert(n < 1001);

	int value[n], weight[n];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &value[i], &weight[i]);
	}

	printf("%0.4f\n", get_max_value(n, w, value, weight));
	
	return 0;
}
