# python3
# Compute the last digit of the sum of n Fibonacci numbers.

import numpy as np
import sys
import time

# Naive implementation, stores whole fibonnaci number, used for stress testing more efficient implementations.
def get_fib_sq_sum_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum = previous**2 + current**2


    #####
    # print(sum)

    for _ in range(n - 1):
        previous, current = current, (previous + current) % 10
        sum = (sum + current**2) % 10
        # print(sum)

    return sum

# More efficient implementation, stores only the ones place of each fibonacci number.
def get_fib_sq_sum_last_digit_table(n):
    fib_table = [0,1]
    fib_sum = [0, 1]
    if n<=1:
        return n

    #####
    print(fib_sum[0])
    print(fib_sum[1])

    for i in range(2,n+1):
        fib_table.append((fib_table[i-1] + fib_table[i-2]))
        fib_sum.append(sum(fib_table)%10)
        print(fib_sum[i])

    return fib_sum

# Efficient implementation given that sum of fibonacci numbers mod 10 is a periodic sequence.
def get_fib_sq_sum_last_digit_eff(n):
    fib_sum_table = [0, 1]
    fib_table = [0, 1]
    if n <= 1:
        return n

    for index in range(2, n+1):

        fib_table.append( (fib_table[index - 1] + fib_table[index - 2]) % 10 )
        fib_sum_table.append( (fib_sum_table[index - 1] + fib_table[index]**2 ) % 10 )
        # print(fib_sum_table[index])

        if (fib_sum_table[index - 1] == 0 and fib_sum_table[index] == 1):
            return fib_sum_table[n % (index - 1)]

    return fib_sum_table[(n)]


def stress_test(fib_range=20):
    counter = 0
    while(True):
        n = np.random.randint(fib_range+1)

        sol1 = get_fib_sq_sum_last_digit_naive(n)
        sol2 = get_fib_sq_sum_last_digit_eff(n)
        assert(sol1 == sol2), f"ERROR: n = {n}\n SOL1: {sol1}\nSOL2: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1

if __name__ == '__main__':

    if len(sys.argv) > 1:
        stress_test(int(sys.argv[1]))
    else:
        n = int(input())
        # print(get_fib_sq_sum_last_digit_naive(n))
        # print("\n")
        # print(get_fib_sq_sum_last_digit_table(n))
        # start = time.time()
        print(get_fib_sq_sum_last_digit_eff(n))
        # print(f"Total time: {time.time()-start}")