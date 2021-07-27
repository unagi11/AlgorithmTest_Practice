# Success
# Details 
# Runtime: 116 ms, faster than 15.48% of Python3 online submissions for Merge Two Binary Trees.
# Memory Usage: 15.5 MB, less than 50.04% of Python3 online submissions for Merge Two Binary Trees.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return self.__str__()

    def __str__(self) -> str:
        return str(self.val)

class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:

        if root1 is None:
            return root2
        
        if root2 is None:
            return root1
        
        # DFS로 풀어보자
        stack1 = [root1]
        stack2 = [root2]
        root3 = TreeNode(root1.val + root2.val)
        stack3 = [root3]

        while stack1 and stack2:

            node1 = stack1.pop()
            node2 = stack2.pop()
            node3 = stack3.pop()

            if node1.left is not None or node2.left is not None:
                node1.left = TreeNode(0) if node1.left is None else node1.left
                node2.left = TreeNode(0) if node2.left is None else node2.left
                node3.left = TreeNode(node1.left.val + node2.left.val)
                stack1.append(node1.left)
                stack2.append(node2.left)
                stack3.append(node3.left)

            if node1.right is not None or node2.right is not None:
                node1.right = TreeNode(0) if node1.right is None else node1.right
                node2.right = TreeNode(0) if node2.right is None else node2.right
                node3.right = TreeNode(node1.right.val + node2.right.val)
                stack1.append(node1.right)
                stack2.append(node2.right)
                stack3.append(node3.right)

        return root3

root1 = TreeNode(1, TreeNode(3, TreeNode(5)), TreeNode(2))
root2 = TreeNode(2, TreeNode(1, None, TreeNode(4)), TreeNode(3, None, TreeNode(7)))

print(Solution().mergeTrees(root1, root2))