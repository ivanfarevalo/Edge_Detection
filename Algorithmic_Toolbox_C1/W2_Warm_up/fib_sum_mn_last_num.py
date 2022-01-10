# python3
# Compute the last digit of the sum of Fibonacci numbers in a given range.

import numpy as np
import sys
import time

# Naive implementation, stores whole fibonnaci number, used for stress testing more efficient implementations.
def get_fib_sum_last_digit_naive(m, n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum = 0 if m >= 2 else 1

    for i in range(2, n + 1):
        previous, current = current, (previous + current) % 10
        if i >= m:
            sum = (sum + current) % 10

    return sum

# More efficient implementation, stores only the ones place of each fibonacci number.
def get_fib_sum_last_digit_table(m, n):
    fib_table = [0,1]
    fib_sum = [0, 1]
    if n<=1:
        return n

    for i in range(2,n+1):
        fib_table.append((fib_table[i-1] + fib_table[i-2]))
        if i >= m:
            fib_sum.append(sum(fib_table)%10)

    return fib_sum

# Efficient implementation given that sum of fibonacci numbers mod 10 is a periodic sequence.
def get_fib_sum_last_digit_eff(m, n):
    fib_sum_table = [0, 1]

    if n <= 1:
        return n

    for index in range(2, n+1):
        fib_sum_table.append((1 + fib_sum_table[index - 1] + fib_sum_table[index - 2]) % 10)

        if (fib_sum_table[index - 1] == 0 and fib_sum_table[index] == 1):
            # Return the sum up to n minus the sum up to (m-1). Add 10 and mod by 10 to get correct output.
            if m == 0:
                return fib_sum_table[n % (index - 1)]
            else:
                return (10 + ((fib_sum_table[n % (index - 1)] - fib_sum_table[(m - 1) % (index - 1)]) % 10)) % 10

    if m == 0:
        return fib_sum_table[n]
    else:
        return (10 + ((fib_sum_table[(n)] - fib_sum_table[(m - 1)]) % 10)) % 10


def stress_test(fib_start=20, fib_end=200):
    counter = 0
    while(True):
        m = np.random.randint(fib_start)
        n = np.random.randint(fib_start, fib_end+1)

        sol1 = get_fib_sum_last_digit_naive(m, n)
        sol2 = get_fib_sum_last_digit_eff(m, n)
        assert(sol1 == sol2), f"ERROR: n = {n} m = {m}\n SOL1: {sol1}\nSOL2: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1

if __name__ == '__main__':

    if len(sys.argv) > 1:
        stress_test(int(sys.argv[1]), int(sys.argv[2]))
    else:
        m, n = map(int, input().split())
        # print(get_fib_sq_sum_last_digit_naive(m, n))
        # print(get_fib_sq_sum_last_digit_table(n))
        # start = time.time()
        print(get_fib_sum_last_digit_eff(m, n))
        # print(f"Total time: {time.time()-start}")