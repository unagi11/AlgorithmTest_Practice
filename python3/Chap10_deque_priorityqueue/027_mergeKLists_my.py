# Success
# Details 
# Runtime: 84 ms, faster than 99.49% of Python3 online submissions for Merge k Sorted Lists.
# Memory Usage: 18.4 MB, less than 27.56% of Python3 online submissions for Merge k Sorted Lists.

from typing import List

import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __str__(self) -> str:
        _str = ""
        index = self
        while index is not None:
            _str += "{} > ".format(index.val)
            index = index.next
        return _str

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap = []

        for i in lists:
            tempNode = i
            while tempNode:
                heapq.heappush(heap, tempNode.val)
                tempNode = tempNode.next      

        newlist = ListNode()
        tempNode = newlist

        while heap:
            tempNode.next = ListNode(heapq.heappop(heap))
            tempNode = tempNode.next

        return newlist.next

_input = [ ListNode(1, ListNode(4, ListNode(5))), ListNode(1, ListNode(3, ListNode(4))), ListNode(2, ListNode(6)) ]

print(Solution().mergeKLists(_input))
