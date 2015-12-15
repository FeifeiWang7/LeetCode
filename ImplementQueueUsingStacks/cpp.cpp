class Queue { public: // Push element x to the back of queue. void push(int x) { _stk.push(x); }

// Removes the element from in front of queue.
void pop(void) {
    if(!_stk.empty())
        {
            while(_stk.size()!=1)
            {
                _rev_stk.push(_stk.top());
                _stk.pop();
            }
            _stk.pop();
            while(!_rev_stk.empty())
            {
                _stk.push(_rev_stk.top());
                _rev_stk.pop();
            }
        }
}

// Get the front element.
int peek(void) {
    int ret=0;
    if(!_stk.empty())
        {
            while(!_stk.empty())
            {
                _rev_stk.push(_stk.top());
                _stk.pop();
            }
            ret=_rev_stk.top();
            while(!_rev_stk.empty())
            {
                _stk.push(_rev_stk.top());
                _rev_stk.pop();
            }
        }
    return ret;
    }

// Return whether the queue is empty.
bool empty(void) {
    return _stk.empty();
}
private:
stack<int> _stk;
stack<int> _rev_stk;
};
/////
class Queue {
public:
    // Two Stack
    stack<int> queue;
    stack<int> reverse;

    // Push element x to the back of queue.
    void push(int x) {
        queue.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!queue.empty()) {
            reverse.push(queue.top());
            queue.pop();
        }
        reverse.pop();
        while (!reverse.empty()) {
            queue.push(reverse.top());
            reverse.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while (!queue.empty()) {
            reverse.push(queue.top());
            queue.pop();
        }
        int result = reverse.top();
        while (!reverse.empty()) {
            queue.push(reverse.top());
            reverse.pop();
        }
        return result;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return queue.empty();
    }
};
///
class Queue {
public:
    stack<int> mystack1, mystack2;
    // Push element x to the back of queue.
    void push(int x) {
        mystack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        //move all the elements from stack1 to stack2
        while(!mystack1.empty()){
            mystack2.push(mystack1.top());
            mystack1.pop();
        }
        //remove the desired element;
        mystack2.pop();
        //put the rest back from stack2 to stack1
        while(!mystack2.empty()){
            mystack1.push(mystack2.top());
            mystack2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        //move all the elements from stack1 to stack2
        while(!mystack1.empty()){
            mystack2.push(mystack1.top());
            mystack1.pop();
        }
        //remove the desired element;
        int temp = mystack2.top();
        //put the rest back from stack2 to stack1
        while(!mystack2.empty()){
            mystack1.push(mystack2.top());
            mystack2.pop();
        }
        return temp;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return mystack1.empty();
    }
};
///
class Queue {
private:
stack<int> st, tmp;
public:
// Push element x to the back of queue.
void push(int x) {
    while(tmp.size()){
        st.push(tmp.top());
        tmp.pop();
    }
    st.push(x);
}

// Removes the element from in front of queue.
void pop(void) {
    while(st.size()){
        tmp.push(st.top());
        st.pop();
    }
    tmp.pop();
}

// Get the front element.
int peek(void) {
    while(st.size()){
        tmp.push(st.top());
        st.pop();
    }
    return tmp.top();
}

// Return whether the queue is empty.
bool empty(void) {
    return !st.size() && !tmp.size();
}
};
/////
class Queue {
public:
    bool iss1;
    stack<int> s1;
    stack<int> s2;

    Queue() : iss1(true){}

    void push(int x)
        {
            if(!iss1)
            {           
                while(!s2.empty())
                {
                    s1.push(s2.top());
                    s2.pop();
                }   
                iss1 = true;
            }
            s1.push(x);
        }

    void pop(void)
        {
            if(iss1)
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                iss1 = false;
            }
            s2.pop();
        }

    int peek(void)
        {
            if(iss1)
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                iss1 = false;
            }
            return s2.top();
        }

    bool empty(void)
        {
            if(iss1)
                return s1.empty();
            else
                return s2.empty();
        }
};
///
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        push_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        reset_pop();
        if (!pop_stack.empty())
            pop_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        reset_pop();
        return pop_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return pop_stack.empty() && push_stack.empty();
    }
private:
    stack<int> push_stack, pop_stack;
    void reset_pop(void) {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
    }
};
///
You can implement queue using just one stack by either making push process costlier or pop costlier. Since we have two functions (top() and pop()) which require the top element of the stack, well make the push() function costlier - that is, for pushing a new element, we recursively pop the stack till it is empty and push it at the bottom of the stack, and take advantage of the recursive call to push back in the popped elements once the recursive call hits the base condition and returns. This implementation makes pop() and peek() functions easier. pop() is just going to pop off the top element in stack and peek() will return the top most element.

class Queue {
public:
    stack<int> s;

    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x){
        if(s.size()==0){
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        pushHelper(x);
        s.push(data);
        return;

    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s.size()==0);
    }
};
///
class Queue { public:

stack<int> s1;
stack<int> s2;
// Push element x to the back of queue.
void push(int x) {
    s1.push(x);

}

// Removes the element from in front of queue.
void pop(void) {
    if(s1.empty())
        return;
    while(!s1.empty())  {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

// Get the front element.
int peek(void) {
    if(s1.empty())
        return -1;
     while(!s1.empty())  {
        s2.push(s1.top());
        s1.pop();
    }
    int t = s2.top();
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    return t;
}

// Return whether the queue is empty.
bool empty(void) {
    return s1.empty();
}
};
///
every elements at most 4 operation type,push in the si stack ,pop from the si stack，push in the so stack,pop from the stack，for one elements,each operation at most once,so the average time of one operation for the queue is O(1)

class Queue {
public:
    // Push element x to the back of queue.
    stack<int> si;
    stack<int> so;
    int n;
    Queue(){
        n=0;
    }
    void push(int x) {
        n++;
        si.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        n--;
        if(!so.empty()){
            so.pop();
        }
        else{
            int l=si.size();
            for(int i=0;i<l;i++){
                so.push(si.top());
                si.pop();
            }
            so.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!so.empty()){
            return so.top();
        }
        else{
            int l=si.size();
            for(int i=0;i<l;i++){
                so.push(si.top());
                si.pop();
            }
            return so.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return(n==0);
    }
};

///
similar idea just make the code more easier to read.

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        m_stack_back.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(m_stack_front.empty())
            this->move_back_2_front();
        m_stack_front.pop();
    }

    // Get the front element.
    int peek(void) {
        if(m_stack_front.empty())
            this->move_back_2_front();

        return m_stack_front.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return m_stack_back.empty() && m_stack_front.empty();
    }
private:
    void move_back_2_front(){
        while(!m_stack_back.empty()){
            m_stack_front.push(m_stack_back.top());
            m_stack_back.pop();
        }
    }
private:
    stack<int> m_stack_back;
    stack<int> m_stack_front;
};

///
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!nums.empty()) {
            helper.push(nums.top());
            nums.pop();
        }
        nums.push(x);
        while (!helper.empty()) {
            nums.push(helper.top());
            helper.pop();
        }
    }
    // Removes the element from in front of queue.
    void pop(void) {
        nums.pop();
    }
    // Get the front element.
    int peek(void) {
        return nums.top();
    }
    // Return whether the queue is empty.
    bool empty(void) {
        return nums.empty();
    }
private:
    std::stack<int> helper, nums;
};
///
I have one input stack, onto which I push the incoming elements, and one output stack, from which I peek/pop. I move elements from input stack to output stack when needed, i.e., when I need to peek/pop but the output stack is empty. When that happens, I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, though, and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).

Ruby

class Queue
    def initialize
        @in, @out = [], []
    end

    def push(x)
        @in << x
    end

    def pop
        peek
        @out.pop
    end

    def peek
        @out << @in.pop until @in.empty? if @out.empty?
        @out.last
    end

    def empty
        @in.empty? && @out.empty?
    end
end
Java

class MyQueue {

    Stack<Integer> input = new Stack();
    Stack<Integer> output = new Stack();

    public void push(int x) {
        input.push(x);
    }

    public void pop() {
        peek();
        output.pop();
    }

    public int peek() {
        if (output.empty())
            while (!input.empty())
                output.push(input.pop());
        return output.peek();
    }

    public boolean empty() {
        return input.empty() && output.empty();
    }
}
C++

class Queue {
    stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }

    void pop(void) {
        peek();
        output.pop();
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};
///
Flip items between two stacks upon push/pop calls.

class Queue {
        stack<int> s, q;
    public:
        // Push element x to the back of queue.
        void push(int x) {
            while(!q.empty()) {
                s.push(q.top());
                q.pop();
            }
            s.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void) {
            while(!s.empty()) {
                q.push(s.top());
                s.pop();
            }
            q.pop();
        }

        // Get the front element.
        int peek(void) {
            while(!s.empty()) {
                q.push(s.top());
                s.pop();
            }
            return q.top();
        }

        // Return whether the queue is empty.
        bool empty(void) {
            return s.empty() && q.empty();        
        }
    };
///
private Stack<Integer> stack1;
private Stack<Integer> stack2;

public MyQueue(){
    stack1 = new Stack<Integer>();
    stack2 = new Stack<Integer>();
 }

// Push element x to the back of queue.
public void push(int x) {
    while(!stack1.isEmpty()){
        stack2.push(stack1.pop());
    }
    stack1.push(x);
    while(!stack2.isEmpty()){
        stack1.push(stack2.pop());
    }
}

// Removes the element from in front of queue.
public void pop() {
    stack1.pop();
}

// Get the front element.
public int peek() {
    return stack1.peek();
}

// Return whether the queue is empty.
public boolean empty() {
    return stack1.isEmpty();
}
