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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # l1, l2 가 둘다 존재한다면 아래 실행
        if l1 and l2:
            # l1의 vale가 더 많으면 스왑 (l1이 작도록)
            if l1.val > l2.val:
                l1, l2 = l2, l1
            # l1 다음 오도록 재귀
            l1.next = self.mergeTwoLists(l1.next, l2)
        # l1이 존재하면 l1 리턴, 없다면 l2
        return l1 or l2

    # 절반으로 쪼개서 merge소트를 시도한다.
    def sortList(self, head: ListNode) -> ListNode:

        if not (head and head.next):
            return head

        half, slow, fast = None, head, head
        while fast and fast.next:
            half, slow, fast = slow, slow.next, fast.next.next
        # 반을 끊어버린다.
        half.next = None

        # 받은 리스트를
        l1 = self.sortList(head)
        l2 = self.sortList(slow)

        # 합쳐준다.
        return self.mergeTwoLists(l1, l2)

_input = ListNode(4,ListNode(2, ListNode(1, ListNode(3))))
Solution().sortList(_input)