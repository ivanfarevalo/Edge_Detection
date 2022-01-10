# Uses python3
import numpy as np

# Naive implementation, tests all numbers between 2 and the smallest of the 2 numbers.
def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd

# Euclidean algorithm implementation: GCD(a, b) = GCD(b, a%b)
def gcd_euclidean(a, b):
    while b!=0:
        a, b = b, a % b
    return a

def stress_test(range = 20000):
    counter = 0
    while (True):
        ab = np.random.randint(1, range + 1, size=2)

        sol1 = gcd_naive(ab[0], ab[1])
        sol2 = gcd_euclidean(ab[0], ab[1])
        assert (sol1 == sol2), f"ERROR: {ab}\n SOL1: {sol1}\nSOL2: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1

if __name__ == "__main__":
    debug = False

    if debug:
        stress_test(2*10^9)
    else:
        a, b = map(int, input().split())
        # print(lcm_naive(a, b))
        print(gcd_euclidean(a, b))
