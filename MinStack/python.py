The code is slightly sped up by computing self.getMin() once in 'push' vs. 3 times.

class MinStack(object):
    def __init__(self):
        self.stack = []

    def push(self, x):
        self.stack.append((x, x if self.getMin() is None or x < self.getMin() else self.getMin()))

    def pop(self):
        self.stack.pop()

    def top(self):
        return None if not self.stack else self.stack[-1][0]

    def getMin(self):
        return None if not self.stack else self.stack[-1][1]
####

class MinStack: # initialize your data structure here. def init(self): self.ordered=[] self.stack=[]

# @param x, an integer
# @return nothing
def push(self, x):
    self.__stack.append(x)
    self.__ordered.append(min([x]+self.__ordered[-1:]))

# @return nothing
def pop(self):
    for i in [self.__stack,self.__ordered]:
        i.pop()

# @return an integer
def top(self):
    return self.__stack[-1]

# @return an integer
def getMin(self):
    return self.__ordered[-1]
#####
The idea is to use pair (element, currentMin) to store element and the minimum at the time element is pushed onto stack

class MinStack:
    def __init__(self):
        self.stack = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        currentMin = self.getMin()
        if currentMin is None or x < currentMin:
            currentMin = x
        self.stack.append((x, currentMin))
        return x

    # @return nothing
    def pop(self):
        self.stack.pop()

    # @return an integer
    def top(self):
        return self.stack[-1][0]

    # @return an integer
    def getMin(self):
        return None if not self.stack else self.stack[-1][1]
