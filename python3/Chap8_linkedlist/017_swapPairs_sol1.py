# Definition for singly-linked list.
from MyListNode import MyListNode as ListNode

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        cur = head

        while cur and cur.next:
            # 값만 교환
            cur.val, cur.next.val = cur.next.val, cur.val
            cur = cur.next.next

        return head
        
#_input = ListNode(1, ListNode(2))
_input = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
print(_input)
print(Solution().swapPairs(_input))