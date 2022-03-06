# Success
# Details 
# Runtime: 2336 ms, faster than 12.28% of Python3 online submissions for Palindrome Pairs.
# Memory Usage: 113.8 MB, less than 5.01% of Python3 online submissions for Palindrome Pairs.

import collections
from typing import List

# 트라이 저장할 노드
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.word_id = -1
        self.palindrome_word_ids = []


class Trie:
    def __init__(self):
        self.root = TrieNode()

    @staticmethod
    def is_palindrome(word: str) -> bool:
        return word[::] == word[::-1]

    # 단어 삽입
    def insert(self, index, word) -> None:
        node = self.root
        for i, char in enumerate(reversed(word)):
            if self.is_palindrome(word[0:len(word) - i]):
                node.palindrome_word_ids.append(index)
            node = node.children[char]
        node.word_id = index

    def search(self, index, word) -> List[List[int]]:
        result = []
        node = self.root

        while word:
            # 내 위치 이전에 단어와 조합하여서 팬림드롬이 되는 경우
            # 판별 로직 3) (본문 설명 참고)
            if node.word_id >= 0:
                if self.is_palindrome(word):
                    result.append([index, node.word_id])
            if not word[0] in node.children:
                return result
            # 앞에서 하나씩 slice 된다.
            node = node.children[word[0]]
            word = word[1:]

        # 현재 위치가 입력 노드의 반전일 경우
        # 판별 로직 1) (본문 설명 참고)
        if node.word_id >= 0 and node.word_id != index:
            result.append([index, node.word_id])

        # 현재 위치 이후 단어중에 팬림드롬이 존재할 경우
        # 판별 로직 2) (본문 설명 참고)
        for palindrome_word_id in node.palindrome_word_ids:
            result.append([index, palindrome_word_id])

        return result


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        trie = Trie()

        for i, word in enumerate(words):
            trie.insert(i, word)

        results = []
        for i, word in enumerate(words):
            results.extend(trie.search(i, word))

        return results

words = ["abcd", "dcba", "lls", "s", "sssll"]
print(Solution().palindromePairs(words))
