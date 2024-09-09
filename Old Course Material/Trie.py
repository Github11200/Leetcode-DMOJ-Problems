class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfString = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        currentNode = self.root

        for letter in word:
            node = currentNode.children.get(letter)
            if node == None:
                node = TrieNode()
                currentNode.children.update({letter: node})
            currentNode = node

        currentNode.endOfString = True
        return "Word successfully inserted"

    def search(self, word):
        currentNode = self.root

        for letter in word:
            if currentNode.children.get(letter) == None:
                return False
            currentNode = currentNode.children.get(letter)

        if currentNode.endOfString == False:
            return False
        else:
            return True

    def delete(self, root, word, index):
        letter = word[index]
        currentNode = root.children.get(letter)
        canLetterBeDeleted = False

        if len(currentNode.children) > 1:
            self.delete(currentNode, word, index + 1)
            return False

        if index == len(word) - 1:
            if len(currentNode.children) >= 1:
                currentNode.endOfString = False
                return False
            else:
                root.children.pop(letter)
                return True

        if currentNode.endOfString == False:
            self.delete(currentNode, word, index + 1)
            return False

        canLetterBeDeleted = self.delete(currentNode, word, index + 1)
        if canLetterBeDeleted == True:
            root.children.pop(letter)
            return True
        else:
            return False


trie = Trie()
trie.insert("test")
trie.insert("apple")
trie.delete(trie.root, "test", 0)
print(trie.search("test"))
