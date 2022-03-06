# Success
# Details 
# Runtime: 32 ms, faster than 65.77% of Python3 online submissions for Invert Binary Tree.
# Memory Usage: 14.3 MB, less than 11.36% of Python3 online submissions for Invert Binary Tree.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        
        if root is None:
            return root

        breadth = [root]

        while breadth:

            temp = []

            for node in breadth:

                node.left, node.right = node.right, node.left

                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)

                breadth = temp

        return root

