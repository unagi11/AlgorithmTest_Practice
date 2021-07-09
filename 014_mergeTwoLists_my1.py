# Definition for singly-linked list.
from typing import List

from numpy.lib.function_base import append


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:

        if l1 is None:
            return l2
        
        if l2 is None:
            return l1

        _list = []

        _node = l1
        while _node:
            _list.append(_node)
            _node = _node.next

        _node = l2
        while _node:
            _list.append(_node)
            _node = _node.next

        _list = sorted(_list, key=lambda x: x.val)

        for i in range(len(_list)-1):
            _list[i].next = _list[i+1]
        
        return _list[0]

_l1 = ListNode(1,ListNode(2,ListNode(3)))
_l2 = ListNode(1,ListNode(3,ListNode(4)))

_output = Solution().mergeTwoLists(_l1, _l2)

print("---")
_node = _output
while _node:
    print(_node.val)
    _node = _node.next