# python3


def is_greater(number, best_num):

    if int(str(number)+str(best_num)) > int(str(best_num)+str(number)):
        return True
    else:
        return False


def compute_max_salary_simple(n, numbers):

    max_number = []

    while(n > 0):

        best_num = 0

        for number in numbers:
            if is_greater(number, best_num):
                best_num = number

        max_number.append(best_num)
        numbers.remove(best_num)
        n -= 1

    return max_number


if __name__ == '__main__':
    n = int(input())
    numbers = list(map(int, input().split()))


    largest_num = compute_max_salary_simple(n, numbers)

    for i in range(len(largest_num)):
        print(largest_num[i], end='')


