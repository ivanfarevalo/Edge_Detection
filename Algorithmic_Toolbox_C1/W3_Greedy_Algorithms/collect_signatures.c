/*
 ============================================================================
 Name        : collect_signatures.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Collect signatures in least amount of trips given time ranges
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


struct Pt_info {
	int num_pts;
	int pt_coord[100];
};

struct Pt_info get_pt_coordinates(int num_segments, int coordinates[][2]) {

	struct Pt_info pts;

	pts.num_pts = 0;

	while(num_segments > 0){

		int i_shortest_endpt = 0;


		for(int i = 0; i < num_segments; ++i){

			if(coordinates[i][1] < coordinates[i_shortest_endpt][1]){
				i_shortest_endpt = i;
			}
		}

		pts.pt_coord[pts.num_pts] = coordinates[i_shortest_endpt][1];

		int i_rm = 0;

		for(int i = 0; i < num_segments; ++i){

			if (coordinates[i][0] > pts.pt_coord[pts.num_pts]){
				coordinates[i_rm][0] = coordinates[i][0];
				coordinates[i_rm][1] = coordinates[i][1];
				++i_rm;
			}
		}

		++pts.num_pts;
		num_segments = i_rm;

	}

	return pts;
}

int main(void) {

	int num_segments;
	scanf("%d", &num_segments);
	assert(num_segments < 101);


	int coordinates[num_segments][2];
	for(int i = 0; i < num_segments; ++i){
		scanf("%d %d", &coordinates[i][0], &coordinates[i][1]);
	}

	struct Pt_info min_pts;
	min_pts = get_pt_coordinates(num_segments, coordinates);

	printf("%d\n", min_pts.num_pts);
	for(int i = 0; i < min_pts.num_pts; ++i){
		printf("%d ", min_pts.pt_coord[i]);
	}

	
	return 0;
}
