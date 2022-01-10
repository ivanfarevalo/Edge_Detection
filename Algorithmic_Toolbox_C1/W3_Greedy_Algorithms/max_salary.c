/*
 ============================================================================
 Name        : max_salary.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Find largest number by concatenating given numbers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


typedef struct Numbered_Array {
    int num_elements;
    int *elements;
} array;

void remove_item(int size, int *head, int *ptr){

    for(int *i = ptr; i < (head+size); i++){
        // printf("\nIN REMOVE: i: %p  (i+1): %p", i, (i+1));
        *i = *(i+1);
    }
}

int count_digits(int num){
        int len = 0;
        do {
        num /= 10;
        ++len;
        } while (num != 0);

        return len;
    }

int is_greater(int num1, int num2){

    int len_num1 = count_digits(num1);
    int len_num2 = count_digits(num2);

    // printf("\nlen_num2= %d", len_num2);
    // printf("\nlen_num1= %d", len_num1);

    int result1 = num2 + pow(10, len_num2) * num1;
    int result2 = num1 + pow(10, len_num1) * num2;

    // printf("\nResutlt1: %d, result2: %d\n", result1, result2);

    if(result1 > result2){
        return 1;
    }else{
        return 0;
    }


}


array get_largest_num(int n, int *nums){

    array largest_num;
    largest_num.num_elements = n;
    largest_num.elements = (int*) malloc(n * sizeof(int));
    

    int indx = 0;

    while(n > 0){

        int *best_num = nums;
        for(int i = 0; i < n; ++i){

            // printf("\n(nums+%d): %d", i, *(nums+i));
            // if(*(nums+i) > *best_num){
            //     best_num  = (nums+i);
            // }

            if(is_greater(*(nums+i), *best_num) ) {
                best_num  = (nums+i);
            }

        }
        *(largest_num.elements + indx) = *best_num;

        // printf("\nLargestNum: %d", *best_num);

        remove_item(n, nums, best_num);

        indx++;
        n--;

        // printf("\nNumsArray: ");
        
        // for(int i = 0; i < n; ++i){
        //     printf("%d ", *(nums+i));
        // }

        
    }

    return largest_num;
}


int main(void) {
    
    int n, *nums;
    scanf("%d", &n);

    nums = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i){
       scanf("%d",  (nums + i));
    }

    // for(int i = 0; i < n; ++i){
    //    printf("%d ",  *(nums + i));
    // }


    array largest_num;
    largest_num = get_largest_num(n, nums);
    // printf("%d\n", largest_num.num_elements);

    for(int i = 0; i < largest_num.num_elements; ++i){
        printf("%d", *(largest_num.elements+i));
    }

    free(nums);
    free(largest_num.elements);

    // int a = is_greater(10, 9);
    // printf("\n%d\n", a);



    return 0;
}