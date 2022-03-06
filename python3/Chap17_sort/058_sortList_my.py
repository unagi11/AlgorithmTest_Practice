# Success
# Details 
# Runtime: 172 ms, faster than 92.06% of Python3 online submissions for Sort List.
# Memory Usage: 30.1 MB, less than 91.31% of Python3 online submissions for Sort List.

# 파이선 리스트로 만들어서 풀기

# Definition for singly-linked list.
from typing import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: ListNode) -> ListNode:

        if head is None:
            return head

        index = head
        arr = []

        while index:
            arr.append(index)
            index = index.next

        arr = sorted(arr, key= lambda x: x.val)
        
        for i in range(len(arr)-1):
            arr[i].next = arr[i+1]

        arr[len(arr)-1].next = None

        return arr[0]


_input = ListNode(4,ListNode(2, ListNode(1, ListNode(3))))
Solution().sortList(_input)