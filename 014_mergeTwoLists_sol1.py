# Definition for singly-linked list.
from typing import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#재귀를 이용한 방식
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if (not l1) or (l2 and l1.val > l2.val):
            l1, l2 = l2, l1
        if l1:
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1

_l1 = ListNode(1,ListNode(2,ListNode(3)))
_l2 = ListNode(1,ListNode(3,ListNode(4)))

_output = Solution().mergeTwoLists(_l1, _l2)

print("---")
_node = _output
while _node:
    print(_node.val)
    _node = _node.next