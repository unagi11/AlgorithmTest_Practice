# Success
# Details 
# Runtime: 40 ms, faster than 98.25% of Python3 online submissions for Balanced Binary Tree.
# Memory Usage: 19.5 MB, less than 5.24% of Python3 online submissions for Balanced Binary Tree.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

import sys;

class Solution:

    def isBalanced(self, root: TreeNode) -> bool:

        if root is None:
            return True

        self.answer = True
        
        def dfs(node, depth):

            if node is None:
                return depth

            left = dfs(node.left, depth+1)
            right = dfs(node.right, depth+1)

            if abs(left - right) > 1:
                self.answer = False
            
            return max(left, right)

        dfs(root, 0)

        return self.answer

_input = TreeNode(3, TreeNode(9), TreeNode(20,  TreeNode(15), TreeNode(7)))
# _input = TreeNode(1, TreeNode(2, TreeNode(3, TreeNode(4), TreeNode(4)), TreeNode(3)), TreeNode(2))
# _input = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))

print(Solution().isBalanced(_input))
