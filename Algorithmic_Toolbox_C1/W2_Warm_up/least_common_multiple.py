# Uses python3
import numpy as np

# Naive implementation, tests all numbers between 2 and the largest common  multiple.
def lcm_naive(a, b):
    current_lcm = a*b
    for d in range(2, a*b + 1):
        if d % a == 0 and d % b == 0 and d < current_lcm:
            current_lcm = d

    return current_lcm

# Euclidean algorithm implementation: GCD(a, b) = GCD(b, a%b)
def lcm_euclidean(a, b):
    gcm = a*b
    while b!=0:
        a, b = b, a % b
    return int(gcm/a)

def stress_test(range = 20000):
    counter = 0
    while (True):
        ab = np.random.randint(1, range + 1, size=2)

        sol1 = lcm_naive(ab[0], ab[1])
        sol2 = lcm_euclidean(ab[0], ab[1])
        assert (sol1 == sol2), f"ERROR: {ab}\n SOL1: {sol1}\nSOL2: {sol2}"
        print(f"Test {counter} succesful")
        counter += 1

if __name__ == "__main__":
    debug = False

    if debug:
        stress_test(2*10**3)
    else:
        a, b = map(int, input().split())
        # print(lcm_naive(a, b))
        print(lcm_euclidean(a, b))
