# 실패

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        depth = 0

        if root is None:
            return 0

        leftfloor = [root.left] if root.left is not None else None
        rightfloor = [root.right] if root.right is not None else None

        floor = leftfloor

        while floor:
            next = []
            depth += 1
            for node in floor:
                if node.left is not None:
                    next.append(node.left)
                if node.right is not None:
                    next.append(node.right)

            floor = next
        
        
        floor = rightfloor

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

_root = TreeNode(1, TreeNode(2))
#_root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))

print(Solution().diameterOfBinaryTree(_root))