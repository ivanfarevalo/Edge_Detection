# python3

# You are organizing a funny competition for children. As a prize fund you have 𝑛
# candies. You would like to use these candies for top 𝑘 places in a competition
# with a natural restriction that a higher place gets a larger number of candies.
# To make as many children happy as possible, you are going to find the largest
# value of 𝑘 for which it is possible.


def calc_max_num_prizes(n):

    if n <= 2:
        return 1, [n]

    min_prize_size = 1
    prizes = []

    while(n > 0):

        if n - min_prize_size > min_prize_size:
            prizes.append(min_prize_size)
            n -= min_prize_size
            min_prize_size += 1
        else:
            prizes.append(n)
            n = 0

    return len(prizes), prizes


if __name__ == '__main__':
    n = int(input())
    num_prizes, prizes = calc_max_num_prizes(n)
    print(f"{num_prizes}")
    for prize in prizes:
        print(f"{prize}", end=" ")