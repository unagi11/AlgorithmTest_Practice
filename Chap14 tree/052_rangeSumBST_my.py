# Success
# Details 
# Runtime: 204 ms, faster than 83.04% of Python3 online submissions for Range Sum of BST.
# Memory Usage: 22.3 MB, less than 59.84% of Python3 online submissions for Range Sum of BST.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    sum = 0

    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        
        if root:
            if root.val < low:
                self.rangeSumBST(root.right, low, high)
            elif low <= root.val and root.val <= high:
                self.sum += root.val
                self.rangeSumBST(root.left, low, high)
                self.rangeSumBST(root.right, low, high)
            elif high < root.val:
                self.rangeSumBST(root.left, low, high)

        return self.sum

root = TreeNode(10, TreeNode(5, TreeNode(3), TreeNode(7)), TreeNode(15, None, TreeNode(18)))
low = 7
high = 15

print(Solution().rangeSumBST(root, low, high))