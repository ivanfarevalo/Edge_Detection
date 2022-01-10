# python3
import sys

def compute_num_refills(distance, miles_per_tank, stops):
    min_num_stops = 0

    while(distance > miles_per_tank):
        farthest_stop = 0
        farthest_index = 0

        for i, stop in enumerate(stops):
            if stop <= miles_per_tank: # Since stops are in order, just update until larger than miles per tank
                farthest_stop = stop
            else:
                break

        if farthest_stop == 0:
            return -1

        distance -= farthest_stop
        stops[:] = [stop - farthest_stop for stop in stops]
        min_num_stops += 1

        for i in range(farthest_index+1):
            del stops[i]

    return min_num_stops


if __name__ == '__main__':

    distance, miles_per_tank, _, *stops = map(int, sys.stdin.read().split())

    print(compute_num_refills(distance, miles_per_tank, stops))