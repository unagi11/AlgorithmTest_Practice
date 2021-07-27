# Success
# Details 
# Runtime: 40 ms, faster than 76.62% of Python3 online submissions for Maximum Depth of Binary Tree.
# Memory Usage: 15.3 MB, less than 96.13% of Python3 online submissions for Maximum Depth of Binary Tree.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: TreeNode) -> int:

        if root is None:
            return 0

        floor = [root]
        depth = 0

        while floor:
            next = []
            depth += 1
            for node in floor:
                if node.left is not None:
                    next.append(node.left)
                if node.right is not None:
                    next.append(node.right)

            floor = next
        
        return depth

_root = TreeNode(3, TreeNode(9), TreeNode(20,TreeNode(15), TreeNode(7)))
print(Solution().maxDepth(_root))