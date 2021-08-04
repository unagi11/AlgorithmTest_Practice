# Success
# Details 
# Runtime: 68 ms, faster than 81.75% of Python3 online submissions for Design Circular Deque.
# Memory Usage: 15 MB, less than 62.79% of Python3 online submissions for Design Circular Deque.

class MyCircularDeque:

    # MyCircularDeque(k) : 데크 사이즈를 k로 지정하는 생성자다.
    def __init__(self, k: int):
        self.maxsize = k
        self.q = [-1 for _ in range(self.maxsize)]

        self.size = 0
        self.front = 0
        self.rear = 0

        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        
    # insertFront() : 데크 처음에 아이템을 추가하고 성공할 경우 true를 리턴한다.
    def insertFront(self, value: int) -> bool:

        if self.size is self.maxsize:
            return False
        else :
            self.front = (self.front + self.maxsize - 1) % self.maxsize if self.size is not 0 else self.front
            self.q[self.front] = value
            self.size += 1

        return True

        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        
    # insertLast() : 데크 마지막에 아이템을 추가하고 성공할 경우 true를 리턴한다.
    def insertLast(self, value: int) -> bool:

        if self.size is self.maxsize:
            return False
        else :
            self.rear = (self.rear + 1) % self.maxsize if self.size is not 0 else self.rear
            self.q[self.rear] = value
            self.size += 1

        return True

        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        
    # deleteFront() : 데크 처음에 아이템을 삭제하고 성공할 경우 true를 리턴한다.
    def deleteFront(self) -> bool:

        if self.size is 0:
            return False
        else :
            self.q[self.front] = -1
            self.size -= 1
            self.front = (self.front + 1) % self.maxsize if self.size is not 0 else self.front

        return True

        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        
    # deleteLast() : 데크 마지막에 아이템을 삭제하고 성공할 경우 true를 리턴한다.
    def deleteLast(self) -> bool:

        if self.size is 0:
            return False
        else :
            self.q[self.rear] = -1
            self.size -= 1
            self.rear = (self.rear + self.maxsize - 1) % self.maxsize if self.size is not 0 else self.rear

        return True

        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        

    def getFront(self) -> int:

        return self.q[self.front]

        """
        Get the front item from the deque.
        """
        

    def getRear(self) -> int:

        return self.q[self.rear]
        
        """
        Get the last item from the deque.
        """
        

    def isEmpty(self) -> bool:

        return self.size is 0
        
        """
        Checks whether the circular deque is empty or not.
        """
        

    def isFull(self) -> bool:

        return self.size is self.maxsize

        """
        Checks whether the circular deque is full or not.
        """
        


# Your MyCircularDeque object will be instantiated and called as such:

_output = []

obj = MyCircularDeque(5)

_output.append(obj.insertFront(1))
_output.append(obj.insertLast(2))
_output.append(obj.insertLast(3))
_output.append(obj.insertLast(3))
_output.append(obj.insertLast(3))
_output.append(obj.insertLast(3))
_output.append(obj.insertLast(3))
_output.append(obj.deleteFront())
_output.append(obj.deleteLast())
_output.append(obj.getFront())
_output.append(obj.getRear())
_output.append(obj.isEmpty())
_output.append(obj.isFull())

print(_output)
