# use two queues
# initialize your data structure here.
def __init__(self):
    self.queue1 = []
    self.queue2 = []
    self.size = 0

# @param x, an integer
# @return nothing
def push(self, x):
    if not self.queue2:
        self.queue1.append(x)
    else:
        self.queue2.append(x)
    self.size += 1

# @return nothing
def pop(self):
    if not self.queue2:
        for _ in xrange(self.size-1):
            self.queue2.append(self.queue1.pop(0))
        self.queue1.pop(0)
    else:
        for _ in xrange(self.size-1):
            self.queue1.append(self.queue2.pop(0))
        self.queue2.pop(0)
    self.size -= 1

# @return an integer
def top(self):
    if not self.queue2:
        for _ in xrange(self.size-1):
            self.queue2.append(self.queue1.pop(0))
        tmp = self.queue1.pop(0)
        self.queue2.append(tmp)
        return tmp
    else:
        for _ in xrange(self.size-1):
            self.queue1.append(self.queue2.pop(0))
        tmp = self.queue2.pop(0)
        self.queue1.append(tmp)
        return tmp

# @return an boolean
def empty(self):
    return self.size == 0

# use one queue   
# initialize your data structure here.
def __init__(self):
    self.queue = collections.deque()
    self.size = 0

# @param x, an integer
# @return nothing
def push(self, x):
    self.queue.append(x)
    for _ in xrange(self.size):
        self.queue.append(self.queue.popleft())
    self.size += 1

# @return nothing
def pop(self):
    self.queue.popleft()
    self.size -= 1

# @return an integer
def top(self):
    # queue peek operation
    return self.queue[0]

# @return an boolean
def empty(self):
    return self.size == 0
#####
The Idea is very simple. Stack is a data structure widely used for simulating recursion, therefore we could create a recursive queue to simulate it. 

One way to do that is 
1. A queue with only two element. 
2. The first element is the statck.top()
3. The second element is another queue. What's in the queue? Please goto 1. 

So when we pushed 1,2,3,4,5 into the queue. The queue ends up looks like this,
(5, (4, (3, (2, (1)))))


from collections import deque

class Stack:
    # initialize your data structure here.
    def __init__(self):
        self.queue = None

    # @param x, an integer
    # @return nothing
    def push(self, x):
        if self.queue == None:
            self.queue = deque([x])
        else:
            self.queue = deque([x, self.queue])

    # @return nothing
    def pop(self):
        if self.queue != None:
            self.queue.popleft()
            try:
                self.queue = self.queue.popleft()
            except:
                self.queue = None

    # @return an integer
    def top(self):
        return self.queue[0]


    # @return an boolean
    def empty(self):
        return self.queue == None
####
class Stack:
    # initialize your data structure here.
    def __init__(self):
        self.stack = collections.deque([])

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.stack.append(x)

    # @return nothing
    def pop(self):
        for i in range(len(self.stack) - 1):
            self.stack.append(self.stack.popleft())

        self.stack.popleft()

    # @return an integer
    def top(self):
        return self.stack[-1]

    # @return an boolean
    def empty(self):
        return len(self.stack) == 0

