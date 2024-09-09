class BinaryHeap:
    def __init__(self, maxsize, heapType):
        self.customList = [None] * (maxsize + 1)
        self.maxsize = maxsize + 1
        self.heapSize = 0
        self.heapType = heapType

    def levelOrderTraversal(self):
        if len(self.customList) == 0:
            return
        else:
            for i in range(1, self.heapSize + 1):
                print(self.customList[i])

    def swap(self, firstIndex, secondIndex):
        temp = self.customList[firstIndex]
        self.customList[firstIndex] = self.customList[secondIndex]
        self.customList[secondIndex] = temp

    def heapify(self, index):
        parentIndex = int(index / 2)
        if index <= 1:
            return
        elif self.heapType == "Min":
            if self.customList[index] < self.customList[parentIndex]:
                self.swap(index, parentIndex)
            self.heapify(parentIndex)
        elif self.heapType == "Max":
            if self.customList[index] > self.customList[parentIndex]:
                self.swap(index, parentIndex)
            self.heapify(parentIndex)

    def insert(self, nodeValue):
        if self.heapSize + 1 == self.maxsize:
            return "Binary heap is full"
        self.heapSize += 1
        self.customList[self.heapSize] = nodeValue
        self.heapify(self.heapSize)

    def heapifyExtractNode(self, index):
        leftIndex = index * 2
        rightIndex = index * 2 + 1

        if leftIndex > self.heapSize or rightIndex > self.heapSize:
            return

        if self.heapType == "Min":
            if self.customList[leftIndex] <= self.customList[rightIndex]:
                self.swap(index, leftIndex)
                self.heapifyExtractNode(leftIndex)
            else:
                self.swap(index, rightIndex)
                self.heapifyExtractNode(rightIndex)
        elif self.heapType == "Max":
            if self.customList[leftIndex] >= self.customList[rightIndex]:
                self.swap(index, leftIndex)
                self.heapifyExtractNode(leftIndex)
            else:
                self.swap(index, rightIndex)
                self.heapifyExtractNode(rightIndex)

    def extractNode(self):
        if self.heapSize < 1:
            return "There are no elements in the binary heap"

        elementToRemove = self.customList[1]

        if self.heapSize < 2:
            self.customList[1] = None
            self.heapSize -= 1
        else:
            self.customList[1] = self.customList[self.heapSize]
            self.customList[self.heapSize] = None
            self.heapSize -= 1

        self.heapifyExtractNode(1)
        return elementToRemove


binaryHeapMin = BinaryHeap(10, "Min")

binaryHeapMin.insert(70)
binaryHeapMin.insert(40)
binaryHeapMin.insert(30)
binaryHeapMin.insert(90)
binaryHeapMin.insert(80)
binaryHeapMin.extractNode()
binaryHeapMin.levelOrderTraversal()
