# Definition for singly-linked list.
from MyListNode import MyListNode as ListNode

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        _head = ListNode()
        _link = _head
        _upper = 0

        node1, node2 = l1, l2

        # l1와 l2가 둘다 None이 될때까지 반복한다.
        while node1 is not None or node2 is not None or _upper is not 0:

            val1 = node1.val if node1 is not None else 0
            val2 = node2.val if node2 is not None else 0

            sum = val1 + val2 + _upper
            _lower = sum % 10
            _upper = sum // 10

            _link.next = ListNode(_lower)
            _link = _link.next

            node1 = node1.next if node1 is not None else node1
            node2 = node2.next if node2 is not None else node2

        return _head.next
        
_list1 = ListNode(9, ListNode(5, ListNode(3)))
_list2 = ListNode(9, ListNode(9, ListNode(4, ListNode(9))))
print(Solution().addTwoNumbers(_list1, _list2))