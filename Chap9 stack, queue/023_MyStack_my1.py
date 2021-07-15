from collections import deque

class MyStack:
    def __init__(self):

        self.queue1 = deque()
        self.queue2 = deque()

        self.MainQueue = self.queue1
        self.SubQueue = self.queue2

        """
        Initialize your data structure here.
        """
        

    def push(self, x: int) -> None:
        self.SubQueue.append(x)
        while len(self.MainQueue) is not 0:
            self.SubQueue.append(self.MainQueue.popleft())

        self.MainQueue, self.SubQueue = self.SubQueue, self.MainQueue

        """
        Push element x onto stack.
        """
        

    def pop(self) -> int:

        return self.MainQueue.popleft()

        """
        Removes the element on top of the stack and returns that element.
        """
        

    def top(self) -> int:
        
        return self.MainQueue[0]

        """
        Get the top element.
        """
        

    def empty(self) -> bool:

        return len(self.MainQueue) is 0

        """
        Returns whether the stack is empty.
        """
        


# Your MyStack object will be instantiated and called as such:
obj = MyStack()
obj.push(1)
obj.push(2)
param_2 = obj.top()
param_3 = obj.pop()
param_4 = obj.empty()

print(param_2, param_3, param_4)