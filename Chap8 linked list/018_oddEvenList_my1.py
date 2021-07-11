# Definition for singly-linked list.
from MyListNode import MyListNode as ListNode

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        link = head
        odd = ListNode()
        even = ListNode()

        odd_head = odd
        even_head = even
        index = 1

        while link:
            if index % 2 is 0:
                even.next = link
                even = even.next
            else:
                odd.next = link
                odd = odd.next

            link = link.next
            index += 1

        if index % 2 is 0:
            even.next = None
        else:
            odd.next = None

        odd.next = even_head.next

        return odd_head.next
        
_input = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
print(_input)
print(Solution().oddEvenList(_input))