# Success
# Details 
# Runtime: 320 ms, faster than 43.66% of Python3 online submissions for Design HashMap.
# Memory Usage: 18.8 MB, less than 20.11% of Python3 online submissions for Design HashMap.

# 코멘트 : 개별 체이닝, 오픈 어드레싱(progressive addressing) 하지 않아서 accept는 받았지만
# 해시가 아님

class MyHashMap:

    def __init__(self):

        self.size = 100000
        self.hash = [-1 for _ in range(self.size)]
     
        """
        Initialize your data structure here.
        """        

    def put(self, key: int, value: int) -> None:

        self.hash[key % self.size] = value

        """
        value will always be non-negative.
        """
        

    def get(self, key: int) -> int:

        return self.hash[key % self.size]

        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        

    def remove(self, key: int) -> None:

        self.hash[key % self.size] = -1 

        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        


# Your MyHashMap object will be instantiated and called as such:

myHashMap = MyHashMap()
myHashMap.put(1, 1)         # The map is now [[1,1]]
myHashMap.put(2, 2)         # The map is now [[1,1], [2,2]]
print(myHashMap.get(1))     # return 1, The map is now [[1,1], [2,2]]
print(myHashMap.get(3))     # return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1)         # The map is now [[1,1], [2,1]] (i.e., update the existing value)
print(myHashMap.get(2))     # return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2)         # remove the mapping for 2, The map is now [[1,1]]
print(myHashMap.get(2))     # return -1 (i.e., not found), The map is now [[1,1]]