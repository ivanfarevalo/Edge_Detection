/*
 ============================================================================
 Name        : max_ad_rev.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Find max ad revenue (max dot product) Ansi-style
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

long get_max_ad_rev(int num_ads, int profit[], int clicks[]) {
	
	long total_revenue = 0;

	while(num_ads > 0){

		int i_max_rev = 0;
		int i_max_clicks = 0;


		for(int i = 0; i < num_ads; ++i){

			if(profit[i] > profit[i_max_rev]){
				i_max_rev = i;
			}
			if(clicks[i] > clicks[i_max_clicks]){
				i_max_clicks = i;
			}
		}

		total_revenue += (long) profit[i_max_rev] * clicks[i_max_clicks];

		// printf("\nTotal Rev: %ld",  total_revenue);

		remove_item(num_ads, i_max_rev, profit);
		remove_item(num_ads, i_max_clicks, clicks);

		num_ads--;

	}

	return total_revenue;
}


int main(void) {

	int num_ads;

	scanf("%d", &num_ads);
	assert(num_ads < 1001);

	int profit[num_ads], clicks[num_ads];
	for(int i = 0; i < num_ads; ++i){
		scanf("%d", &profit[i]);
	}
	for(int i = 0; i < num_ads; ++i){
		scanf("%d", &clicks[i]);
	}

	printf("%ld\n", get_max_ad_rev(num_ads, profit, clicks));
	
	return 0;
}
