# python3
import numpy as np


def max_pair_product_brute_force(numbers: []) -> int:
    '''Brute force approach used to check max_pair_solution in stress test'''
    assert (len(numbers) > 1), "Length should be more than 2"
    max_product = 0
    for i in range(len(numbers)):
        for j in range(len(numbers)):
            if i != j and numbers[i]*numbers[j] > max_product:
                max_product = numbers[i]*numbers[j]
    return max_product


def max_pair_product_sol1(numbers: []) -> int:
    '''Iterate through array twice and pick max value'''
    assert(len(numbers)>1), "Length should be more than 2"

    top_num_1 = 0
    for i in range(1, len(numbers)):
        if numbers[i] >= numbers[top_num_1]:
            top_num_1 = i

    top_num_2 = top_num_1-1
    for i in range(0, len(numbers)):
        if i != top_num_1 and numbers[i] >= numbers[top_num_2]:
            top_num_2 = i

    return numbers[top_num_1]*numbers[top_num_2]


def max_pair_product_sol2(numbers : []) -> int:
    '''Iterate through array and keep pointers at 2 highest numbers'''
    assert (len(numbers) > 1), "Length should be more than 2"
    max_idx_1 = 0
    max_idx_2 = 1
    for i in range(1, len(numbers)):
        if numbers[i]>numbers[max_idx_1]:
            max_idx_2 = max_idx_1
            max_idx_1 = i
        elif numbers[i]>numbers[max_idx_2]:
            max_idx_2 = i

    return numbers[max_idx_1]*numbers[max_idx_2]


def stress_test(max_test_size = 1000):
    counter = 0
    while(True):
        num_elements = np.random.randint(2,max_test_size)
        numbers = np.random.randint(100, size=num_elements)
        sol1 = max_pair_product_sol2(numbers)
        sol2 = max_pair_product_brute_force(numbers)
        assert(sol1 == sol2), f"ERROR: {numbers}\n SOL!: {sol1}\nSOL@: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1


if __name__ == '__main__':
    debug = False

    if debug:
        # RUN STRESS STEST
        stress_test(100)
    else:
        num_elements = int(input()) # Needed for grader
        numbers = [num for num in map(int, input().split())]
        print(max_pair_product_sol2(numbers))

