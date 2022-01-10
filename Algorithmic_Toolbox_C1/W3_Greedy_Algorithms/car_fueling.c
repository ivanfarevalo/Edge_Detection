/*
 ============================================================================
 Name        : car_fueling.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Find min times to refuel and get from A to B Ansi-style
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

void add_to_array(int size, int num, int array[]){

	for(int i = 0; i < size; ++i){
		array[i] += num;
	}
}

int get_min_refills(int d, int m, int n, int stops[]) {
	
	int total_stops = 0;

	while(d > m){

		int max_i = -1;

		for(int i = 0; i < n; ++i){

			if (stops[i] <= m ) {
				max_i = i;
			}else{
				break;
			}
		}

		if(max_i == -1){
			return -1;
		}

		total_stops++;
		d -= stops[max_i];
		add_to_array(n, -1*stops[max_i], stops);
		remove_item(n, max_i, stops);
		n--;


	}

	return total_stops;
}


int main(void) {

	int distance, miles_per_gallon, num_stops;

	scanf("%d\n%d\n%d", &distance, &miles_per_gallon, &num_stops);
	assert(num_stops < 301);

	int stops[num_stops];
	for(int i = 0; i < num_stops; ++i){
		scanf("%d", &stops[i]);
	}

	printf("%d\n", get_min_refills(distance, miles_per_gallon, num_stops, stops));
	
	return 0;
}
