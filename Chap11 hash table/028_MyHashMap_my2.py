# Success
# Details 
# Runtime: 228 ms, faster than 83.17% of Python3 online submissions for Design HashMap.
# Memory Usage: 17.3 MB, less than 78.38% of Python3 online submissions for Design HashMap.
# 코멘트 : 공간을 10000개만 사용해서 가능하도록 오픈 어드래싱으로 재설계

class MyHashMap:

    def __init__(self):

        self.size = 0
        self.maxSize = 8000
        self.table = [(-1, -1) for _ in range(self.maxSize)]

        """
        Initialize your data structure here.
        """
    
    def myHashFunc(self, key):
        index = key % self.maxSize
        return index

    def put(self, key: int, value: int) -> None:

        if self.size == self.maxSize:
            print("공간이 부족..")
            return

        index = self.myHashFunc(key)

        # 빈 index를 찾거나, 기존의 key 위치까지 전진한다.
        while self.table[index][0] != -1 and self.table[index][0] != '#' and self.table[index][0] != key:
            index = index + 1 if index < self.maxSize -1 else 0
        
        self.size += 1
        self.table[index] = (key, value)

        """
        value will always be non-negative.
        """
        

    def get(self, key: int) -> int:
        index = self.myHashFunc(key)

        # key와 일치하는 index를 찾을때까지 전진한다.
        while self.table[index][0] != key:
            if self.table[index][0] == -1:
                return -1
            index = index + 1 if index < self.maxSize -1 else 0

        return self.table[index][1]

        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        

    def remove(self, key: int) -> None:
        index = self.myHashFunc(key)

        # key와 일치하는 index를 찾을때까지 전진한다.
        while self.table[index][0] != key:
            if self.table[index][0] == -1:
                return
            index = index + 1 if index < self.maxSize -1 else 0

        # 비석 (중요!)
        self.table[index] = ('#', -1)

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