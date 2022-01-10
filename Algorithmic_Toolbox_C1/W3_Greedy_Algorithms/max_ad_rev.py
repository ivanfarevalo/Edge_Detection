# python3

# Greedy algorithm to find max dot product between two sequences.

def find_max_revenue(num_ads, ad_profits, ad_clks):
    total_revenue = 0

    while(num_ads > 0):
        biggest_profit = -10**5
        most_clks = -10**5

        for i in range(num_ads):

            if ad_profits[i] > biggest_profit:
                biggest_profit = ad_profits[i]
            if ad_clks[i] > most_clks:
                most_clks = ad_clks[i]

        total_revenue += biggest_profit*most_clks
        num_ads -= 1
        ad_profits.remove(biggest_profit)
        ad_clks.remove(most_clks)

    return total_revenue

if __name__ == '__main__':
    num_ads = int(input())
    ad_profits = list(map(int, input().split()))
    ad_clks = list(map(int, input().split()))

    print(find_max_revenue(num_ads, ad_profits, ad_clks))