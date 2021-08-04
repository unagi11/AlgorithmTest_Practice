# Success
# Details 
# Runtime: 228 ms, faster than 14.71% of Python3 online submissions for Kth Largest Element in an Array.
# Memory Usage: 15.3 MB, less than 22.05% of Python3 online submissions for Kth Largest Element in an Array.

from typing import List

# from BinaryHeap import BinaryHeap
class BinaryHeap:
    def __init__(self):
        self.items = [None]
    
    def __len__(self):
        return len(self.items) - 1
    
    def _percolate_up(self):
        i = len(self)
        parent = i // 2
        while parent > 0:
            if self.items[i] < self.items[parent]:
                self.items[parent], self.items[i] = \
                    self.items[i], self.items[parent]
            i = parent
            parent = i // 2

    def insert(self, k):
        self.items.append(k)
        self._percolate_up()
    
    def _percolate_down(self, idx):
        left = idx * 2
        right = idx * 2 + 1
        smallest = idx 
        if left <= len(self) and self.items[left] < self.items[smallest]:
            smallest = left
        if right <= len(self) and self.items[right] < self.items[smallest]:
            smallest = right
        
        if smallest != idx:
            self.items[idx], self.items[smallest] = \
                self.items[smallest], self.items[idx]
            self._percolate_down(smallest)

    def extract(self):
        extracted = self.items[1]
        self.items[1] = self.items[len(self)]
        self.items.pop()
        self._percolate_down(1)
        return extracted

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = BinaryHeap()

        for i in nums:
            heap.insert(-i)

        answer = 0

        for i in range(k):
            answer = heap.extract()

        return -answer
        
nums = [3,2,1,5,6,4]
k = 2
print(Solution().findKthLargest(nums, k))