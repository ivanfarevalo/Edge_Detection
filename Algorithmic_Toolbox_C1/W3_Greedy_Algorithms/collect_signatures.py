# python3

# You are given a set
# of segments on a line and your goal is to mark as few points on a line as possible
# so that each segment contains at least one marked point.

def compute_num_points(num_segments, segment_coords):
    num_points = 0
    point_coord = []

    while(num_segments > 0):

        # Look for smallest right endpoint, remove any segments that contain it.
        smallest_endpoint = segment_coords[0][1]
        segments_to_remove = []

        for i, segment in enumerate(segment_coords):

            if segment[1] < smallest_endpoint:
                smallest_endpoint = segment[1]

        for i, segment in enumerate(segment_coords):

            if segment[0] <= smallest_endpoint and segment[1] >= smallest_endpoint:
                segments_to_remove.append(segment)

        for segment in segments_to_remove:
            segment_coords.remove(segment)
            num_segments -= 1

        num_points += 1
        point_coord.append(smallest_endpoint)

    return num_points, point_coord





if __name__ == '__main__':
    num_segments = int(input())
    segment_coords = [list(map(int, input().split())) for i in range(num_segments)]
    min_num_pts, pt_coord = compute_num_points(num_segments, segment_coords)

    print(f"{min_num_pts}")
    for pt in pt_coord:
        print(f"{pt}", end=" ")