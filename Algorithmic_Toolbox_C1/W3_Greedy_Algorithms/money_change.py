# Uses python3

def get_change(money):
    num_coins = 0
    while(money > 0):
        if money >= 10:
            num_coins += money // 10
            money = money % 10
        elif money >= 5:
            num_coins += money // 5
            money = money % 5
        else:
            num_coins += money
            money = 0

    return num_coins

if __name__ == '__main__':

    m = int(input())
    print(get_change(m))