class MyCircularQueue:

    def __init__(self, k: int):
        # 최대 크기
        self.maxsize = k
        self.q = [-1 for _ in range(self.maxsize)]

        print(self.q)

        self.size = 0
        self.front = 0
        self.rear = 0
        return

    def enQueue(self, value: int) -> bool:
        # 이미 현재 큐 사이즈가 맥스 사이즈면 넣을수 없다.
        if self.size is self.maxsize:
            return False
        # 큐 사이즈가 맥스 사이즈보다 적으면 넣을수 있다.
        else :
            self.rear = (self.rear + 1) % self.maxsize if self.size is not 0 else self.rear
            self.q[self.rear] = value
            self.size += 1

        return True
        

    def deQueue(self) -> bool:
        # 값이 존재해야 dequeue를 할 수 있다.

        if self.size is 0:
            return False
        else :
            self.q[self.front] = -1
            self.size -= 1
            self.front = (self.front + 1) % self.maxsize if self.size is not 0 else self.front

        return True
        
    def Front(self) -> int:
        return self.q[self.front]
        

    def Rear(self) -> int:
        return self.q[self.rear]
        

    def isEmpty(self) -> bool:       
        return self.size is 0
        

    def isFull(self) -> bool:
        return len(self.q) is self.size

# Your MyCircularQueue object will be instantiated and called as such:

_output = []
obj = MyCircularQueue(3)

_output.append(obj.isEmpty())

_output.append(obj.enQueue(1))
_output.append(obj.enQueue(2))
_output.append(obj.enQueue(3))
_output.append(obj.enQueue(4))

print(obj.q)
_output.append(obj.Rear())
_output.append(obj.isFull())
_output.append(obj.deQueue())
_output.append(obj.enQueue(4))

print(obj.q)
_output.append(obj.Rear())
_output.append(obj.Front())

print(_output)
