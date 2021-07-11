# Definition for singly-linked list.
from MyListNode import MyListNode as ListNode

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:

        # 초기 검사 head가 None이거나 head.next가 None이면 자기 자신을 다시 돌려준다.
        if head is None or head.next is None:
            return head

        _result = ListNode(0, head)

        # 변수 4개를 사용한 스왑
        t0 = _result
        t1 = head
        t2 = head.next
        t3 = head.next.next

        while t1 and t2:

            t0.next = t2
            t1.next = t3
            t2.next = t1

            t0 = t1
            t1 = t3
            t2 = t3.next if t3 is not None else None
            t3 = t2.next if t2 is not None else None

        return _result.next
        
#_input = ListNode(1, ListNode(2))
_input = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
print(_input)
print(Solution().swapPairs(_input))