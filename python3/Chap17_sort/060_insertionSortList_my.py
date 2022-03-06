# Success
# Details 
# Runtime: 1536 ms, faster than 56.70% of Python3 online submissions for Insertion Sort List.
# Memory Usage: 16.3 MB, less than 67.60% of Python3 online submissions for Insertion Sort List.

# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __str__(self) -> str:
        _str = ""
        index = self
        while index is not None:
            _str += "{} > ".format(index.val)
            index = index.next
        return _str

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:

        if not head:
            return head

        import sys
        front = ListNode(-sys.maxsize, head)

        index1 = head.next
        head.next = None

        while index1:
            next = index1.next

            back2 = front
            index2 = front.next

            while index2:
                if index2.val > index1.val:
                    break
                back2 = index2
                index2 = index2.next
            
            back2.next = index1
            index1.next = index2

            index1 = next

        return front.next

head = ListNode(4,ListNode(3,ListNode(1,ListNode(2))))
print(Solution().insertionSortList(head))