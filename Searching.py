def binarySearch(customList, value):
    l = 0
    h = len(customList) - 1
    m = 0

    while l <= h:
        m = round((l + h) / 2)

        print(m)

        if value == customList[m]:
            return 1
        elif value < customList[m]:
            h = m - 1
        else:
            l = m + 1

    return -1


testList = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
print(binarySearch(testList, 19))
