# Definition for singly-linked list.
from MyListNode import MyListNode as ListNode

# 설명 : 재귀를 이용한 풀이

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def reverse(node: ListNode, prev: ListNode = None):
            # 노드가 Null이면 prev를 리턴한다. (마지막)
            if not node:
                return prev

            # 오른쪽 노드를 next에 저장하고
            # 링크를 이전으로 바꾼다.
            next, node.next = node.next, prev

            # 오른쪽 노드를 node 현재노드 prev로 다시 반복한다.
            return reverse(next, node)
        return reverse(head)

#_input = ListNode(1, ListNode(2))
_input = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
print(_input)
print(Solution().reverseList(_input))