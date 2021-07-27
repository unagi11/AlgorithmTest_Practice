# Success
# Details 
# Runtime: 388 ms, faster than 64.79% of Python3 online submissions for Longest Univalue Path.
# Memory Usage: 18.2 MB, less than 14.98% of Python3 online submissions for Longest Univalue Path.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    longest = 0
    def longestUnivaluePath(self, root: TreeNode) -> int:

        if root is None:
            return 0

        def dfs(univalue, node):

            left, right = 0, 0
            if node.left is not None:
                if node.left.val == univalue:
                    left = dfs(univalue, node.left)
                else:
                    dfs(node.left.val, node.left)
            
            if node.right is not None:
                if node.right.val == univalue:
                    right = dfs(univalue, node.right)
                else:
                    dfs(node.right.val, node.right)

            print(self.longest, left, right)
            self.longest = max(self.longest, left + right)

            return max(left, right) + 1
        
        dfs(root.val, root)

        return self.longest

root = TreeNode(5, TreeNode(1, TreeNode(4), TreeNode(4)), TreeNode(5, TreeNode(5)))

print(Solution().longestUnivaluePath(root))