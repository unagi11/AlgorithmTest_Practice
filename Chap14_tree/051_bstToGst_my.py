# Success
# Details 
# Runtime: 32 ms, faster than 67.81% of Python3 online submissions for Binary Search Tree to Greater Sum Tree.
# Memory Usage: 14.4 MB, less than 31.51% of Python3 online submissions for Binary Search Tree to Greater Sum Tree.

# Definition for a binary tree node.
from typing import NoReturn

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:

        value = 0

        # 상위 노드에서 value를 계승한다.
        def backTracking(node, value):

            # right가 none이 아니라면, 오른자식 value를 사용한다.
            if node.right is not None:
                value = backTracking(node.right, value)

            # 현재 노드값을 더해서 노드값으로 사용한다.
            value += node.val
            node.val = value

            # left로 값을 보낸다.
            if node.left is not None:
                value = backTracking(node.left, value)
    
            # left를 순회한 후 값을 상위 노드로 보낸다.
            return value

        value = backTracking(root, value)

        return root


root = TreeNode(4, TreeNode(1,TreeNode(0), TreeNode(2, None,TreeNode(3))), TreeNode(6, TreeNode(5), TreeNode(7, None,TreeNode(8))))
print(Solution().bstToGst(root))