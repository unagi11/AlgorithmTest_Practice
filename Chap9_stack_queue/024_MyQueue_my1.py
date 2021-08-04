class MyQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []
        self.MainStack = self.stack1
        self.SubStack = self.stack2

        """
        Initialize your data structure here.
        """
        

    def push(self, x: int) -> None:

        while len(self.MainStack) is not 0:
            self.SubStack.append(self.MainStack.pop())

        self.MainStack.append(x)

        while len(self.SubStack) is not 0:
            self.MainStack.append(self.SubStack.pop())
        
        """
        Push element x to the back of queue.
        """
        

    def pop(self) -> int:

        return self.MainStack.pop()

        """
        Removes the element from in front of queue and returns that element.
        """
        

    def peek(self) -> int:

        return self.MainStack[len(self.MainStack)-1]

        """
        Get the front element.
        """
        

    def empty(self) -> bool:

        return len(self.MainStack) is 0

        """
        Returns whether the queue is empty.
        """
        


# Your MyQueue object will be instantiated and called as such:
obj = MyQueue()
obj.push(1)
obj.push(2)
obj.push(3)
obj.push(4)
obj.push(5)
param_2 = obj.pop()
param_3 = obj.peek()
param_4 = obj.empty()

print(param_2, param_3, param_4)