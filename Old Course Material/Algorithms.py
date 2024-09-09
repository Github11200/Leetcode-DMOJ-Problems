from array import *
import numpy as np
from queue import Queue


def DigitSum(n):
    assert n >= 0 and int(n) == n, "number has to be a positive integer"
    if n < 10:
        return n
    return DigitSum(int(n / 10)) + (n % 10)


def power(x, exp):
    assert int(
        exp) == exp and exp >= 0, "the exponent must be a positive integer greater than or equal to 0"
    if exp == 1:
        return x
    elif exp == 0:
        return 1
    else:
        return x * power(x, exp - 1)


def gcd(a, b):
    assert int(a) == a and int(b) == b, "both numbers must be integers"
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def integerToBinary(x):
    assert x < 0, "x must be a whole number"
    if x == 0:
        return x
    return x % 2 + 10 * integerToBinary(int(x / 2))


def binaryToInteger(x):
    assert x < 0, "x must be in binary, and must be positive"
    if x == 0:
        return x
    return x % 10 + 2 * binaryToInteger(int(x / 10))


def numberOfSquares(n):
    if n == 1:
        return 1
    return pow(n, 2) + numberOfSquares(n - 1)


class TreeNode:
    def __init__(self, data):
        self.data = data
        self.leftNode = None
        self.rightNode = None


# rootNode = TreeNode(1)
# leftNode = TreeNode(2)
# rightNode = TreeNode(3)

# leftNodeTwo = TreeNode(4)
# rightNodeTwo = TreeNode(5)

# leftNodeThree = TreeNode(6)
# rightNodeThree = TreeNode(7)

# leftNode.leftNode = leftNodeTwo
# leftNode.rightNode = rightNodeTwo

# rightNode.leftNode = leftNodeThree
# rightNode.rightNode = rightNodeThree

# rootNode.leftNode = leftNode
# rootNode.rightNode = rightNode


def levelOrder(rootNode):
    if not rootNode:
        return

    nodesQueue = Queue()
    nodesQueue.put(rootNode)
    while not (nodesQueue.empty()):
        root = nodesQueue.get()
        print(root.data)

        if root.leftNode is not None:
            nodesQueue.put(root.leftNode)
        if root.rightNode is not None:
            nodesQueue.put(root.rightNode)


def insertNode(rootNode, newNode):
    if not rootNode:
        rootNode = newNode
    else:
        nodesQueue = Queue()
        nodesQueue.put(rootNode)

        while not nodesQueue.empty():
            root = nodesQueue.get()

            if root.leftNode is None:
                root.leftNode = newNode
                return "Successfully Inserted"
            else:
                nodesQueue.put(root.leftNode)

            if root.rightNode is None:
                root.rightNode = newNode
                return "Successfully Inserted"
            else:
                nodesQueue.put(root.rightNode)

        return "Not inserted"


def getDeepestNode(rootNode):
    if not rootNode:
        return

    nodesQueue = Queue()
    nodesQueue.put(rootNode)
    root = None

    while not nodesQueue.empty():
        root = nodesQueue.get()

        if root.leftNode is not None:
            nodesQueue.put(root.leftNode)
        if root.rightNode is not None:
            nodesQueue.put(root.rightNode)

    return root


def deleteDeepestNode(rootNode, deepestNode):
    if not rootNode:
        return

    nodesQueue = Queue()
    nodesQueue.put(rootNode)

    while not nodesQueue.empty():
        root = nodesQueue.get()

        if root == deepestNode:
            root = None
            return "Node successfully deleted"

        if root.leftNode:
            if root.leftNode == deepestNode:
                root.leftNode = None
                return "Node successfully deleted"
            nodesQueue.put(root.leftNode)

        if root.rightNode:
            if root.rightNode == deepestNode:
                root.rightNode = None
                return "Node successfully deleted"
            nodesQueue.put(root.rightNode)

    return "Could not delete node"


def deleteNode(rootNode, nodeToDelete):
    if not rootNode:
        return

    nodesQueue = Queue()
    nodesQueue.put(rootNode)

    while not nodesQueue.empty():
        root = nodesQueue.get()

        if root.leftNode:
            if root.leftNode.data == nodeToDelete:
                deepestNode = getDeepestNode(root)
                root.leftNode.data = deepestNode.data
                deleteDeepestNode(root, deepestNode)
                return "Successfully deleted node"
            nodesQueue.put(root.leftNode)

        if root.rightNode:
            if root.rightNode.data == nodeToDelete:
                deepestNode = getDeepestNode(root)
                root.rightNode.data = deepestNode.data
                deleteDeepestNode(root, deepestNode)
                return "Successfully deleted node"
            nodesQueue.put(root.rightNode)

    return "Could not delete the node"


def deleteBinarytree(rootNode):
    rootNode.data = None
    rootNode.leftNode = None
    rootNode.rightNode = None


# deleteBinarytree(rootNode)
# levelOrder(rootNode)


class BinaryTree:
    def __init__(self, maxsize):
        self.customList = maxsize * [None]
        self.maxsize = maxsize
        self.lastUsedIndex = 0

    def insert(self, value):
        if self.lastUsedIndex + 1 == self.maxsize:
            return "The binary tree is full"
        self.customList[self.lastUsedIndex + 1] = value
        self.lastUsedIndex += 1
        return "The item was sucessfully inserted"

    def search(self, value):
        for node in self.customList:
            if node == value:
                return "Sucess"
        return "Not found"

    def preOrderTraversal(self, index=1):
        if index > self.lastUsedIndex:
            return
        print(self.customList[index])
        self.preOrderTraversal(index * 2)
        self.preOrderTraversal(index * 2 + 1)

    def inOrderTraversal(self, index=1):
        if index > self.lastUsedIndex:
            return
        self.inOrderTraversal(index * 2)
        print(self.customList[index])
        self.inOrderTraversal(index * 2 + 1)

    def postOrderTraversal(self, index=1):
        if index > self.lastUsedIndex:
            return
        self.postOrderTraversal(index * 2)
        self.postOrderTraversal(index * 2 + 1)
        print(self.customList[index])

    def levelOrderTraversal(self):
        for i in range(1, self.lastUsedIndex + 1):
            print(self.customList[i])

    def deleteNode(self, value):
        if self.lastUsedIndex == 0:
            return "There are no elements to delete in the tree"

        for i in range(1, self.lastUsedIndex + 1):
            if self.customList[i] == value:
                self.customList[i] = self.customList[self.lastUsedIndex]
                self.customList[self.lastUsedIndex] = None
                self.lastUsedIndex -= 1
                return "The node was successfully deleted"


# binaryTree = BinaryTree(8)
# binaryTree.insert(1)
# binaryTree.insert(2)
# binaryTree.insert(3)
# binaryTree.insert(4)
# binaryTree.insert(5)
# binaryTree.insert(6)
# binaryTree.levelOrderTraversal()
# print("/////////////////////////////////")
# binaryTree.deleteNode(2)
# binaryTree.levelOrderTraversal()


class BSTNode:
    def __init__(self, value):
        self.value = value
        self.leftNode = None
        self.rightNode = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, newNode):
        self.root = self.insertInternal(self.root, newNode)

    def insertInternal(self, rootNode, newNode):
        if not rootNode:
            return newNode

        if newNode.value > rootNode.value:
            rootNode.rightNode = self.insertInternal(
                rootNode.rightNode, newNode)
        else:
            rootNode.leftNode = self.insertInternal(rootNode.leftNode, newNode)

        return rootNode

    def preOrderTraversal(self):
        self.preOrderTraversalInternal(self.root)

    def inOrderTraversal(self):
        self.inOrderTraversalInternal(self.root)

    def postOrderTraversal(self):
        self.postOrderTraversalInternal(self.root)

    def preOrderTraversalInternal(self, rootNode):
        if not rootNode:
            return

        print(rootNode.value)
        self.preOrderTraversalInternal(rootNode.leftNode)
        self.preOrderTraversalInternal(rootNode.rightNode)

    def inOrderTraversalInternal(self, rootNode):
        if not rootNode:
            return

        self.inOrderTraversalInternal(rootNode.leftNode)
        print(rootNode.value)
        self.inOrderTraversalInternal(rootNode.rightNode)

    def postOrderTraversalInternal(self, rootNode):
        if not rootNode:
            return

        self.postOrderTraversalInternal(rootNode.leftNode)
        self.postOrderTraversalInternal(rootNode.rightNode)
        print(rootNode.value)

    def levelOrderTraversal(self):
        if not self.root:
            return

        nodesQueue = Queue()
        nodesQueue.put(self.root)
        while not nodesQueue.empty():
            root = nodesQueue.get()
            print(root.value)

            if root.leftNode:
                nodesQueue.put(root.leftNode)

            if root.rightNode:
                nodesQueue.put(root.rightNode)

    def searchNode(self, value):
        return self.searchNodeInternal(self.root, value)

    def searchNodeInternal(self, root, value):
        if not root:
            return False

        if root.value == value:
            return True

        if value > root.value:
            return self.searchNodeInternal(root.rightNode, value)
        else:
            return self.searchNodeInternal(root.leftNode, value)

    def minValueNode(self, root):
        if root.leftNode:
            return self.minValueNode(root.leftNode)
        else:
            return root

    def deleteNode(self, value):
        self.root = self.deleteNodeInternal(self.root, value)

    def deleteNodeInternal(self, root, value):
        if not root:
            return root

        if value == root.value:
            if not root.leftNode:
                temp = root.rightNode
                root = None
                return temp

            if not root.rightNode:
                temp = root.leftNode
                root = None
                return temp

            temp = self.minValueNode(root.rightNode)
            root.value = temp.value
            root.rightNode = self.deleteNodeInternal(
                root.rightNode, temp.value)
        elif value > root.value:
            root.rightNode = self.deleteNodeInternal(root.rightNode, value)
        else:
            root.leftNode = self.deleteNodeInternal(root.leftNode, value)

        return root


bst = BST()
bst.insert(BSTNode(5))
bst.insert(BSTNode(4))
bst.insert(BSTNode(7))
print(bst.deleteNode(4))
bst.levelOrderTraversal()
