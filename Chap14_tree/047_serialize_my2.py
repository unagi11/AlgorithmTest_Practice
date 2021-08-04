# 7/27/2021 20:43	Time Limit Exceeded	N/A	N/A	python3

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return str(self.val)

import collections

class Codec:
    def serialize(self, root: TreeNode):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """

        if root is None:
            return []

        _dict = collections.defaultdict(int)

        def dfs(node, index):
            if node is None:
                return

            _dict[index] = node.val
            
            leftIndex = (index+1)*2-1
            dfs(node.left, leftIndex)

            rightIndex = (index+1)*2
            dfs(node.right, rightIndex)

        dfs(root, 0)

        serial = [None for _ in range(max(_dict)+1)]
        
        for key in _dict:
            serial[key] = _dict[key]
        
        return serial

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """

        if len(data) == 0:
            return None

        root = TreeNode(data[0])

        length = len(data)

        def dfs(node, index):
            # 데이터가 없다면 해당 노드는 존재하지 않는다.
            if data[index] is None:
                return None
            # 데이터가 있다면 해당 노드의 값을 수정해준다.
            else:
                node.val = data[index]

            leftIndex = (index+1)*2-1
            if leftIndex < length:
                node.left = dfs(TreeNode(), leftIndex)

            rightIndex = (index+1)*2
            if rightIndex < length:
                node.right = dfs(TreeNode(), rightIndex)
            
            return node
            
        dfs(root, 0)

        return root
        

# Your Codec object will be instantiated and called as such:
root = TreeNode(1,TreeNode(2),TreeNode(3,TreeNode(4),TreeNode(5)))
ser = Codec()
deser = Codec()

ans = deser.deserialize(ser.serialize(root))