from numpy import outer


def split_the_array():
    nums = [1, 1, 1, 1]
    nums1 = []
    nums2 = []

    items = {}
    for num in nums:
        if num in items:
            if items[num] + 1 > 2:
                return False
            else:
                items[num] += 1
        else:
            items[num] = 1

    return True

# Could not figure out this problem


def find_the_largest_area_of_square_inside_two_rectangles():
    bottomLeft = [[1, 2], [1, 2]]
    topRight = [[4, 5], [2, 3]]
    largest_area = 0

    outer_points = {}

    is_intersection = False
    i = 0
    while i < len(bottomLeft):
        for j in range(bottomLeft[i][0], topRight[i][0] + 1):
            if not f"{j} {bottomLeft[i][1]}" in outer_points:
                outer_points[f"{j} {bottomLeft[i][1]}"] = [j, bottomLeft[i][1]]
            else:
                is_intersection = True

        for j in range(topRight[i][1], bottomLeft[i][1]):
            if not f"{topRight[i][0]} {j}" in outer_points:
                outer_points[f"{topRight[i][0]} {j}"] = [topRight[i][0], j]
            else:
                is_intersection = True

        for j in range(bottomLeft[i][0], topRight[i][0] + 1):
            if not f"{j} {topRight[i][1]}" in outer_points:
                outer_points[f"{j} {topRight[i][1]}"] = [j, topRight[i][1]]
            else:
                is_intersection = True

        for j in range(bottomLeft[i][1] + 1, topRight[i][1]):
            if not f"{bottomLeft[i][0]} {j}" in outer_points:
                outer_points[f"{bottomLeft[i][0]} {j}"] = [bottomLeft[i][0], j]
            else:
                is_intersection = True

        i += 1

    if not is_intersection:
        return 0

    for i, bottomCoor in enumerate(bottomLeft):
        for j, topCoor in enumerate(topRight):
            if j == i or abs(topCoor[0] - bottomCoor[0]) != abs(topCoor[1] - bottomCoor[1]):
                continue
            elif not f"{bottomCoor[0]} {topCoor[1]}" in outer_points or not f"{topCoor[0]} {bottomCoor[1]}" in outer_points:
                continue
            else:
                largest_area = abs(
                    topCoor[0] - bottomCoor[1]) * abs(topCoor[1] - bottomCoor[1])

    return largest_area


print(find_the_largest_area_of_square_inside_two_rectangles())
