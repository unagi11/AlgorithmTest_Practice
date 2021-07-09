# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 앞뒤로 O(1)로 접근 가능한 deque 사용
import collections

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        q = collections.deque()

        if not head:
            return True
        
        node = head

        while node is not None:
            q.append(node.val)
            node = node.next
        
        while len(q) > 1:
            if q.popleft() != q.pop():
                return False
            
        return True

_input = ListNode(1, ListNode(2, ListNode(2, ListNode(1))))
print(Solution().isPalindrome(_input))