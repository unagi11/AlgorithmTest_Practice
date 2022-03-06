# Definition for singly-linked list.
from MyListNode import MyListNode as ListNode

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:        
        link = head

        arr = []

        while link is not None:
            arr.append(link.val)
            link = link.next

        if (arr == arr[::-1]):
            return True
        else:
            return False

_input = ListNode(1, ListNode(1, ListNode(2, ListNode(1))))
print(Solution().isPalindrome(_input))