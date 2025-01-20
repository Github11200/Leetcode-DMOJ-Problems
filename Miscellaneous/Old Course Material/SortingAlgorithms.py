import math


def bubbleSort(customList):
    for i in range(0, len(customList) - 1):
        for j in range(0, len(customList) - 1 - i):
            if customList[j] >= customList[j + 1]:
                customList[j], customList[j +
                                          1] = customList[j + 1], customList[j]

    return customList


def selectionSort(customList):
    for i in range(len(customList)):
        minValueIndex = i
        for j in range(i, len(customList)):
            if customList[j] < customList[minValueIndex]:
                minValueIndex = j
        customList[i], customList[minValueIndex] = customList[minValueIndex], customList[i]

    return customList


def insertionSort(customList):
    for i in range(1, len(customList)):
        key = customList[i]
        j = i - 1
        while j >= 0 and key < customList[j]:
            customList[j + 1] = customList[j]
            j -= 1
        customList[j + 1] = key

    return customList


def bucketSort(customList):
    numberOfBuckets = round(math.sqrt(len(customList)))
    maxValue = max(customList)
    arr = []

    for i in range(numberOfBuckets):
        arr.append([])

    for value in customList:
        bucket = math.ceil((value * numberOfBuckets) / maxValue)
        arr[bucket - 1].append(value)

    k = 0
    for i in range(len(arr)):
        arr[i] = insertionSort(arr[i])
        for j in range(len(arr[i])):
            customList[k] = arr[i][j]
            k += 1

    return customList


def merge(customList, l, m, r):
    leftList = customList[l:m + 1]
    rightList = customList[m + 1:r + 1]

    i = 0
    j = 0
    k = l
    while i < len(leftList) and j < len(rightList):
        if leftList[i] <= rightList[j]:
            customList[k] = leftList[i]
            i += 1
        else:
            customList[k] = rightList[j]
            j += 1
        k += 1

    while i < len(leftList):
        customList[k] = leftList[i]
        k += 1
        i += 1

    while j < len(rightList):
        customList[k] = rightList[j]
        k += 1
        j += 1

    return customList


def sortMerge(customList, l, r):
    if l < r:
        m = (l + r) // 2
        sortMerge(customList, l, m)
        sortMerge(customList, m + 1, r)
        merge(customList, l, m, r)
    return customList


def partition(customList, low, high):
    i = low - 1
    pivot = customList[high]

    for j in range(low, high):
        if customList[j] <= pivot:
            i += 1
            customList[i], customList[j] = customList[j], customList[i]
    customList[i + 1], customList[j + 1] = customList[j + 1], customList[i + 1]

    return i + 1


def quickSort(customList, low, high):
    if low < high:
        pi = partition(customList, low, high)
        quickSort(customList, low, pi - 1)
        quickSort(customList, pi + 1, high)

    return customList


testList = [23, 6, 1, 9, 3]
testListTwo = [2, 5, 8, 11, 13]

print(quickSort(testList, 0, len(testList) - 1))
