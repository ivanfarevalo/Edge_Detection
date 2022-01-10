# python3
# Given an integer 𝑛, find the 𝑛th Fibonacci number 𝐹𝑛.

import numpy as np

# Naive implementation, used for stress testing more efficient implementations.
def calc_fib_naive(n):
    if (n <= 1):
        return n

    return calc_fib_naive(n - 1) + calc_fib_naive(n - 2)

# More efficient implementation, stores values in list.
def calc_fib_table(n):
    fib_table = [0,1]
    if n<=1:
        return n

    for i in range(2,n+1):
        fib_table.append(fib_table[i-1] + fib_table[i-2])

    return fib_table

# More efficient implementation, stores only two values at a time until reach desired fibonacci number
def calc_fib_mem_eff(n):

    if n<=1:
        return n

    current, next = 0, 1

    for i in range(n-1):
        current, next = next, current + next

    return next

def stress_test(fib_range=20):
    counter = 0
    while(True):
        n = np.random.randint(fib_range+1)

        sol1 = calc_fib_naive(n)
        sol2 = calc_fib_mem_eff(n)
        assert(sol1 == sol2), f"ERROR: {n}\n SOL1: {sol1}\nSOL2: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1

if __name__ == '__main__':
    debug = True

    if debug:
        stress_test()
    else:
        n = int(input())
        # print(get_fibonacci_remainder_naive(n))
        print(calc_fib_table(n))