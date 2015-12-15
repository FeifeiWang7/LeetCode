The idea is to simulate a queue using two stacks (same as previous posts). I use python list as the underlying data structure for stack and add a "move()" method to simplify code: it moves all elements of the "inStack" to the "outStack" when the "outStack" is empty. Here is the code

class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.inStack, self.outStack = [], []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.inStack.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        self.move()
        self.outStack.pop()

    def peek(self):
        """
        :rtype: int
        """
        self.move()
        return self.outStack[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return (not self.inStack) and (not self.outStack) 

    def move(self):
        """
        :rtype nothing
        """
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
###
class Queue:
    # initialize your data structure here.
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.stack1.append(x)

    # @return nothing
    def pop(self):
        if len(self.stack2)!=0:
            self.stack2.pop()
        else:
            while len(self.stack1)!=0:
                self.stack2.append(self.stack1.pop())
            self.stack2.pop()

    # @return an integer
    def peek(self):
        if len(self.stack2)!=0:
            return self.stack2[-1]
        else:
            while len(self.stack1)!=0:
                self.stack2.append(self.stack1.pop())
            return self.stack2[-1]

    # @return an boolean
    def empty(self):
        if len(self.stack1)==0 and len(self.stack2)==0:
            return True
        else:
            return False
###
I guess maybe this way can be easy readable

class Queue(object): def init(self): """ initialize your data structure here. """ self.temp=[]

def push(self, x):
    """
    :type x: int
    :rtype: nothing
    """
    return self.temp.append(x)

def pop(self):
    """
    :rtype: nothing
    """
    return self.temp.remove(self.temp[0]) if len(self.temp)!=0 else None

def peek(self):
    """
    :rtype: int
    """

    return self.temp[0] if len(self.temp)!=0 else None
def empty(self):
    """
    :rtype: bool
    """
    #while len(self.temp)!=0:
    #    self.temp.pop()
    return True if len(self.temp)==0 and self.temp is not None else False
