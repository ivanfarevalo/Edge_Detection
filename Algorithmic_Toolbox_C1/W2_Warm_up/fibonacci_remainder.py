# python3
# Compute the last digit of the n-th Fibonacci number.

import numpy as np

# Naive implementation, stores whole fibonnaci number, used for stress testing more efficient implementations.
def get_fibonacci_remainder_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m


# Efficient implementation given that fibonacci mod m is a periodic sequence.
def get_fibonacci_remainder_mem_eff(n, m):
    fib_table, pisano_table = [0, 1], [0, 1]
    if n <= 1:
        return n % m

    for index in range(2, n+1):
        fib_table.append((fib_table[index - 1] + fib_table[index - 2]))
        pisano_table.append(fib_table[index] % m)
        if (pisano_table[index - 1] == 0 and pisano_table[index] == 1):
            return pisano_table[n % (index - 1)]
    return pisano_table[(index)]


def stress_test(fib_range=2000, m_range=2000):
    counter = 0
    while(True):
        n = np.random.randint(1, fib_range)
        m = np.random.randint(1, m_range)

        sol1 = get_fibonacci_remainder_naive(n, m)
        sol2 = get_fibonacci_remainder_mem_eff(n,m)
        assert(sol1 == sol2), f"ERROR: {n}\n SOL1: {sol1}\nSOL2: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1

if __name__ == '__main__':
    debug = False

    if debug:
        stress_test()
    else:
        n, m = map(int,input().split())
        # print(get_fibonacci_remainder_naive(n,m))
        # print(f'n: {n}\n m: {m}')
        print(get_fibonacci_remainder_mem_eff(n,m))