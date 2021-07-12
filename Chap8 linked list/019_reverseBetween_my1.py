from typing import List
from MyListNode import MyListNode as ListNode

# Success
# Details 
# Runtime: 60 ms, faster than 5.53% of Python3 online submissions for Reverse Linked List II.
# Memory Usage: 14.3 MB, less than 70.29% of Python3 online submissions for Reverse Linked List II.

class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:

        if left is right:
            return head

        # 역전 이전과 이후 노드 기록
        nodehead = ListNode(0, head)
        nodeIndex = nodehead
        for i in range(right+1):
            if i is left-1:
                reversehead = nodeIndex
            nodeIndex = nodeIndex.next
            reverseend = nodeIndex
        
        reversebeforeend = reversehead.next
        old = reversehead.next
        cur = old.next
        new = cur.next
        for i in range(right - left):
            cur.next = old

            old = cur
            cur = new
            new = new.next if new is not None else None
 
        reversehead.next = old
        reversebeforeend.next = reverseend
    
        return nodehead.next

                
_input = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
print(_input)
print(Solution().reverseBetween(_input, 2, 4))