# Definition for singly-linked list.
from MyListNode import MyListNode as ListNode

# 설명 : List Node를 기록하는 old, cur, new 변수를 사용하여 (풀이 보니까 더 빠르게 접근 가능한듯)
# cur.next = old 연산을 통해서 리스트 방향을 역전시킨다.

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:

        # 초기 검사 head가 None이거나 head.next가 None이면 자기 자신을 다시 돌려준다.
        if head is None or head.next is None:
            return head

        old = None 
        cur = head
        new = head.next

        while new:
            cur.next = old
                        
            old = cur
            cur = new
            new = new.next
        
        cur.next = old

        return cur

_input = ListNode(1, ListNode(2))
#_input = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
print(_input)
print(Solution().reverseList(_input))