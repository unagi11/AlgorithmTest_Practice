# Success
# Details 
# Runtime: 143 ms, faster than 5.38% of Python3 online submissions for Convert Sorted Array to Binary Search Tree.
# Memory Usage: 15.6 MB, less than 59.96% of Python3 online submissions for Convert Sorted Array to Binary Search Tree.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import List


class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:

        def recursive(node, lists):
            if len(lists) == 0:
                return None
            else:
                node.val = lists[len(lists)//2]
                left = TreeNode()
                right = TreeNode()
                node.left = recursive(left, lists[:len(lists)//2])
                node.right = recursive(right, lists[len(lists)//2+1:])
                return node

        root = TreeNode(nums[len(nums)//2])
        
        recursive(root, nums)

        return root

nums = [-10,-3,0,5,9]

print(Solution().sortedArrayToBST(nums).val)