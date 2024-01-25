def bubbleSort(customList):
    for i in range(len(customList) - 1):
        for j in range(len(customList) - i - 1):
            if customList[j] >= customList[j + 1]:
                customList[j], customList[j +
                                          1] = customList[j + 1], customList[j]

    return customList


def selectionSort(customList):
    for i in range(len(customList)):
        minValue = i
        for j in range(i + 1, len(customList)):
            if customList[j] < customList[minValue]:
                minValue = j
        customList[i], customList[minValue] = customList[minValue], customList[i]

    return customList


def insertionSort(customList):
    for i in range(1, len(customList)):
        

    return customList


testList = [5, 9, 2, 7, 1, 4]
print(insertionSort(testList))
