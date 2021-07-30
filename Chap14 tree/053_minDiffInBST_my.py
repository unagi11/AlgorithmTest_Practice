# Success
# Details 
# Runtime: 24 ms, faster than 96.98% of Python3 online submissions for Minimum Distance Between BST Nodes.
# Memory Usage: 14.3 MB, less than 39.38% of Python3 online submissions for Minimum Distance Between BST Nodes.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 중위순회로 풀어야함
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        
        import sys
        self.minDiff = sys.maxsize

        def tour(node, oldVal):

            # 왼쪽 먼저 순회
            if node.left:
                oldVal = tour(node.left, oldVal)
            
            self.minDiff = min(self.minDiff, node.val-oldVal)
            oldVal = node.val

            if node.right:
                oldVal = tour(node.right, oldVal)
    
            return oldVal

        tour(root, -sys.maxsize)

        return self.minDiff

# root = TreeNode(4,TreeNode(2,TreeNode(1),TreeNode(3)),TreeNode(6))
root = TreeNode(1, TreeNode(-4), TreeNode(48, TreeNode(12), TreeNode(52)))
print(Solution().minDiffInBST(root))