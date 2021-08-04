# Success
# Details 
# Runtime: 152 ms, faster than 81.26% of Python3 online submissions for Implement Trie (Prefix Tree).
# Memory Usage: 28 MB, less than 76.52% of Python3 online submissions for Implement Trie (Prefix Tree).

import collections

# 사도 트라이..
class Trie:

    def __init__(self):
        self.mid = collections.defaultdict(list)
        self.word = set()

        """
        Initialize your data structure here.
        """
        

    def insert(self, word: str) -> None:
        self.word.add(word)
        temp = ""
        for i in word:
            temp += i
            self.mid[temp].append(word)

        """
        Inserts a word into the trie.
        """
        

    def search(self, word: str) -> bool:

        return word in self.word

        """
        Returns if the word is in the trie.
        """
        

    def startsWith(self, prefix: str) -> bool:

        return prefix in self.mid

        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        

# Your Trie object will be instantiated and called as such:
trie = Trie()
print(trie.insert("apple"))
print(trie.search("apple"))
print(trie.search("app"))
print(trie.startsWith("app"))
print(trie.insert("app"))
print(trie.startsWith("app"))
print(trie.startsWith("dd"))
print(trie.search("app"))