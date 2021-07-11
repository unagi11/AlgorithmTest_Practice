# Definition for singly-linked list.
class MyListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def __str__(self) -> str:
        _str = ""
        index = self
        while index is not None:
            _str += "{} > ".format(index.val)
            index = index.next
        return _str
