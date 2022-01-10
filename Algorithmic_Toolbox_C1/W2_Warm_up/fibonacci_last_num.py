# python3
# Compute the last digit of the n-th Fibonacci number.

import numpy as np

# Naive implementation, stores whole fibonnaci number, used for stress testing more efficient implementations.
def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10

# More efficient implementation, stores only the ones place of each fibonacci number.
def get_fibonacci_last_digit_table(n):
    fib_table = [0,1]
    if n<=1:
        return n

    for i in range(2,n+1):
        fib_table.append((fib_table[i-1] + fib_table[i-2]) % 10)

    return fib_table[-1]

# More memory efficient implementation, stores only two variables.
def get_fibonacci_last_digit_mem_eff(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, (previous + current) % 10

    return current

def stress_test(fib_range=20):
    counter = 0
    while(True):
        n = np.random.randint(fib_range+1)

        sol1 = get_fibonacci_last_digit_naive(n)
        sol2 = get_fibonacci_last_digit_table(n)
        assert(sol1 == sol2), f"ERROR: {n}\n SOL1: {sol1}\nSOL2: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1

if __name__ == '__main__':
    debug = False

    if debug:
        stress_test()
    else:
        n = int(input())
        # print(get_fibonacci_remainder_naive(n))
        print(get_fibonacci_last_digit_mem_eff(n))