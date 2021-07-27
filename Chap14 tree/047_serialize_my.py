# 7/27/2021 20:43	Time Limit Exceeded	N/A	N/A	python3

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Codec:
    def serialize(self, root: TreeNode):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """

        if root is None:
            return []

        # 너비우선탐색으로 serialize할거다
        serial = []
        breadth = [root]

        # breadth에 None만 존재할때까지 내려간다.
        while breadth.count(None) != len(breadth):
            next = []
            for node in breadth:
                if node is None:
                    serial.append(None)
                    next.append(None)
                    next.append(None)
                else:
                    serial.append(node.val)
                    next.append(node.left)                
                    next.append(node.right)
            breadth = next
        
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

        memory = [None for _ in range(length)]
        memory[0] = root


        for index in range(length):

            if data[index] is None:
                continue

            leftIndex = (index+1)*2-1
            if leftIndex < length:
                memory[index].left = TreeNode(data[leftIndex]) if data[leftIndex] is not None else None
                memory[leftIndex] = memory[index].left

            rightIndex = (index+1)*2
            if rightIndex < length:
                memory[index].right = TreeNode(data[rightIndex]) if data[rightIndex] is not None else None
                memory[rightIndex] = memory[index].right

        return root
        

# Your Codec object will be instantiated and called as such:
root = TreeNode(1,TreeNode(2),TreeNode(3,TreeNode(4),TreeNode(5)))
ser = Codec()
deser = Codec()

ans = deser.deserialize(ser.serialize(root))