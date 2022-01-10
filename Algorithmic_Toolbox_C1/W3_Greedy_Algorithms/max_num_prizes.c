/*
 ============================================================================
 Name        : max_num_prizes.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Max number of different numbers that add up to given number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Numbered_Array {
    int num_elements;
    int *elements;
} array;


struct Numbered_Array get_max_elements(int n){

    array prizes;
    prizes.num_elements = 0;
    prizes.elements = (int*) malloc(1 * sizeof(int));

    if(n <= 2){
        prizes.num_elements += 1;
        *prizes.elements = n;
        
    }else{
        int min_num = 1;
        int *head = prizes.elements;

        while(n > 0){
            prizes.num_elements += 1;
            prizes.elements = realloc(prizes.elements, (prizes.num_elements+1) * sizeof(int));
            
            if(n - min_num > min_num){
                *head = min_num;
                head++;
                n -= min_num;
                min_num++;
            }else{
                *head = n;
                head++;
                n = 0;
            }
            
        }

    }

    return prizes;
}


int main(void) {
    
    int n;
    scanf("%d", &n);

    array prizes;
    prizes = get_max_elements(n);
    printf("%d\n", prizes.num_elements);

    for(int i = 0; i< prizes.num_elements; ++i){
        printf("%d ", *(prizes.elements+i));
    }

    free(prizes.elements);



    return 0;
}