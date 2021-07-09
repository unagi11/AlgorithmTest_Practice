# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

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