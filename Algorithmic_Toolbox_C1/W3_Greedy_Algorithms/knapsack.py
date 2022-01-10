# Uses python3

def get_optimal_value(capacity, weights, values):

    total_value = 0
    while(capacity > 0 and len(weights) != 0):
        largest_value = 0
        index = 0
        for i, value in enumerate(values):
            if value/weights[i] > largest_value:
                index = i
                largest_value = value/weights[i]
        total_value += values[index] * min(capacity, weights[index]) / weights[index]
        capacity -= min(capacity, weights[index])
        del weights[index]
        del values[index]

    return total_value


if __name__ == "__main__":
    n, capacity = map(int, input().split())
    data = [list(map(int, input().split())) for i in range(n)]
    values = [pair[0] for pair in data]
    weights = [pair[1] for pair in data]
    print("{0:.4f}".format(get_optimal_value(capacity, weights, values)))
