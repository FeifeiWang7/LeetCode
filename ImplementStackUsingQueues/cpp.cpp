class Stack { public: queue q;

// Push element x onto stack.
void push(int x) {
    q.push(x);
}

// Removes the element on top of the stack.
void pop() {
    int n = q.size();
    for (int i=0;i<n-1;i++){
        q.push(q.front());
        q.pop();
    }
    q.pop();
}

// Get the top element.
int top() {
    return q.back();
}

// Return whether the stack is empty.
bool empty() {
    return q.empty(); 
}
};
///
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        qu.push(x);
        back = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        int sz = qu.size();
        if(sz == 0)
            return;
        for(int i=0;i<sz-1;i++)
        {
            back = qu.front();
            qu.pop();
            qu.push(back);
        }
        qu.pop();
    }

    // Get the top element.
    int top() {
        if(!qu.empty())
            return back;
        return -1;
    }

    // Return whether the stack is empty.
    bool empty() {
        return qu.empty();
    }
private:
    queue<int> qu;
    int back;
};
///
class Stack {
  typedef shared_ptr<queue<int>> QuePtr;
public:
  // Push element x onto stack.
  void push(int x) {
    if (old_que->empty()) old_que->push(x);
    else {
      if (status || new_que->size() == old_que->size()) {
        update();
      }
      new_que->push(x);
      status = false;
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    reorder(new_que, true);
    new_que->empty() ? old_que->pop() : new_que->pop();
  }

  // Get the top element.
  int top() {
    reorder(new_que, true);
    return new_que->empty() ? old_que->front() : new_que->front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return new_que->empty() && old_que->empty();
  }

private:
  QuePtr old_que = make_shared<queue<int>>();  // Always sorted.
  QuePtr new_que = make_shared<queue<int>>();  // Not sorted unless reordered.
  bool status = false;

private:
  // Reorder only works on the new queue.
  void update() {
    reorder(new_que, true);
    // Combine old_que and new_que.
    while (!old_que->empty()) {
      new_que->push(old_que->front());
      old_que->pop();
    }
    swap(old_que, new_que);
  }

  void reorder(QuePtr que, bool flag = false) {
    if (status || que->size() == 0 || que->size() == 1) return;
    QuePtr temp = make_shared<queue<int>>();
    for (int i = 0; i < que->size() /2 ; ++i) {
      temp->push(que->front());
      que->pop();
    }
    reorder(temp);
    reorder(que);
    while (!temp->empty()) {
      que->push(temp->front());
      temp->pop();
    }
    if (flag) status = true;
  }
};
///
class MyStack {
private Queue<Integer> queue = new LinkedList<Integer>();
public void push(int x) {
    int t = queue.size();
    queue.offer(x);
    while(t-- > 0) {
        queue.offer(queue.poll());
    }
}

// Removes the element on top of the stack.
public void pop() {
    queue.poll();
}

// Get the top element.
public int top() {
    return queue.peek();
}

// Return whether the stack is empty.
public boolean empty() {
    return queue.isEmpty();
}
}
///
class Stack {
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};
///
Inspired by the O(1) Java and Javascript solutions.

class Stack {
public:
    std::queue<void*>* queue = new std::queue<void*>;

    // Push element x onto stack.
    void push(int x) {
        int* pushElem = new int(x);
        std::queue<void*>* newQueue = new std::queue<void*>;
        newQueue->push(pushElem);
        newQueue->push(queue);
        queue = newQueue;
    }

    // Removes the element on top of the stack.
    void pop() {
        int* popElem = (int*)queue->front();
        queue->pop();
        delete popElem;

        std::queue<void*>* newQueue = (std::queue<void*>*)queue->front();
        queue->pop();
        delete queue;
        queue = newQueue;
    }

    // Get the top element.
    int top() {
        int* popElem = (int*)queue->front();
        return *popElem;
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue->empty();
    }
};

////
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        myStack.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = myStack.size();
        for(int i = 0; i < len - 1; i++) {
            myStack.push(myStack.front());
            myStack.pop();
        }
        myStack.pop();
    }

    // Get the top element.
    int top() {
        int len = myStack.size();
        if(len) {
            for(int i = 0; i < len - 1; i++) {
                myStack.push(myStack.front());
                myStack.pop();
            }
        }
        int ans = myStack.front();
        myStack.push(ans);
        myStack.pop();
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return myStack.empty();
    }
private:
    std::queue<int> myStack;
};
////
class Stack { private: queue myque; public: // Push element x onto stack.

void push(int x) {
    if(myque.empty()){
        myque.push(x);
        return;
    }
    myque.push(x);
    for(int i=0;i<myque.size()-1;i++){
        myque.push(myque.front());
        myque.pop();
    }
}

// Removes the element on top of the stack.
void pop() {
    myque.pop();
}

// Get the top element.
int top() {
    return myque.front();
}

// Return whether the stack is empty.
bool empty() {
    return myque.empty();
}
};
////
class Stack {
    queue<int> rev_q;
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int> temp_q;
        temp_q.push(x);
        while (!rev_q.empty()) {
            temp_q.push(rev_q.front());
            rev_q.pop();
        }

        rev_q = temp_q;
    }

    // Removes the element on top of the stack.
    void pop() {
        rev_q.pop();
    }

    // Get the top element.
    int top() {
        return rev_q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return rev_q.empty();
    }
};
/////
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        unsigned int size = s.size();
        this->s.push(x);
        while (size--){
            s.push(s.front());
            s.pop();
            }
    }

    // Removes the element on top of the stack.
    void pop() {
        s.pop();
    }

    // Get the top element.
    int top() {
       return s.front(); 
    }

    // Return whether the stack is empty.
    bool empty() {
        return s.empty();
    }
private:
    queue<int> s;
};
/////
class MyStack 
{
    Queue<Integer> queue;

    public MyStack()
    {
        this.queue=new LinkedList<Integer>();
    }

    // Push element x onto stack.
    public void push(int x) 
    {
       queue.add(x);
       for(int i=0;i<queue.size()-1;i++)
       {
           queue.add(queue.poll());
       }
    }

    // Removes the element on top of the stack.
    public void pop() 
    {
        queue.poll();
    }

    // Get the top element.
    public int top() 
    {
        return queue.peek();
    }

    // Return whether the stack is empty.
    public boolean empty() 
    {
        return queue.isEmpty();
    }
}
/////
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        nums.push(x);
    }
    // Removes the element on top of the stack.
    void pop() {
        if (!empty()) {
            int len = nums.size();
            for (int i = 0; i != len - 1; ++i) {
                nums.push(nums.front());
                nums.pop();
            }
            nums.pop();
        }
    }
    // Get the top element.
    int top() {
        return nums.back();
    }
    // Return whether the stack is empty.
    bool empty() {
        return nums.empty();
    }
private:
    std::queue<int> nums;
};
Thanks for StefanPochmann to remind me that back() is forbidden, so the right solution should be:

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        int len = nums.size();
        nums.push(x);
        for (int i = 0; i != len; ++i) {
            nums.push(nums.front());
            nums.pop();
        }
    }
    // Removes the element on top of the stack.
    void pop() {
        nums.pop();
    }
    // Get the top element.
    int top() {
        return nums.front();
    }
    // Return whether the stack is empty.
    bool empty() {
        return nums.empty();
    }
private:
    std::queue<int> nums;
};
