class MyStack {

Queue<Integer> q1 = new LinkedList<Integer>();
Queue<Integer> q2 = new LinkedList<Integer>();

public void push(int x) {
    q1.offer(x);
    return;
}

// Removes the element on top of the stack.
public void pop() {
    if(q1.isEmpty()){
        return;
    }
    int size = q1.size();

    while(!q1.isEmpty()){
        if(size == 1){
            int discard = q1.poll();
            break;
        }
        q2.offer(q1.poll());
        size--;
    }

    while(!q2.isEmpty()){
        q1.offer(q2.poll());
    }
    return;
}

// Get the top element.
public int top() {
    int tmp = 0;
    if(q1.isEmpty()){
        return tmp;
    }
    int size = q1.size();
    while(!q1.isEmpty()){
       if(size == 1){
           tmp = q1.peek();
       } 
       q2.offer(q1.poll());
       size--;
    }

    while(!q2.isEmpty()){
        q1.offer(q2.poll());
    }
    return tmp;
}

// Return whether the stack is empty.
public boolean empty() {
    return q1.isEmpty();
}
}

///
class MyStack {

private Queue<Integer> mQueue = null;

MyStack() {        
    mQueue = new ArrayDeque<Integer>();
}

// Push element x onto stack.
public void push(int x) {
    Queue<Integer> tmp = new ArrayDeque<>();
    tmp.add((Integer)x);
    int len = mQueue.size();
    for (int i = 0; i < len; i++) {
        tmp.add(mQueue.element());
        mQueue.poll();
    }
    mQueue = tmp;
}

// Removes the element on top of the stack.
public void pop() {
    mQueue.remove();
}

// Get the top element.
public int top() {
    return mQueue.peek();
}

// Return whether the stack is empty.
public boolean empty() {
    return mQueue == null ? true : mQueue.isEmpty();
}
}
///
class MyStack {
    Queue<Integer> q1 = new LinkedList<Integer>();
    Queue<Integer> q2 = new LinkedList<Integer>();
    int size = 0;

    // Push element x onto stack.
    public void push(int x) {
        q1.add(x);
        size++;
    }

    // Removes the element on top of the stack.
    public void pop() {
        while(size > 1){
            q2.add(q1.poll());
            size--;
        }
        q1.poll();
        size--;
        while(q2.peek() != null){
            q1.add(q2.poll());
            size++;
        }
    }

    // Get the top element.
    public int top() {
        while(size > 1){
            q2.add(q1.poll());
            size--;
        }
        int res = q1.peek();
        while(q2.peek() != null){
            q1.add(q2.poll());
            size++;
        }
        q1.add(q1.poll());
        return res;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q1.peek() == null;
    }
}
///
class MyStack { // Push element x onto stack. List queue = new ArrayList();

public void push(int x) {
    queue.add(x);
}

// Removes the element on top of the stack.
public void pop() {
    List<Integer> temp = new ArrayList<Integer>();
    while(queue.size() > 1) temp.add(queue.remove(0));
    while(temp.size() > 0) queue.add(temp.remove(0));
    queue.remove(0);
}

// Get the top element.
public int top() {
    List<Integer> temp = new ArrayList<Integer>();
    while(queue.size() > 1) temp.add(queue.remove(0));
    int result = queue.remove(0);
    temp.add(result);
    while(temp.size() > 0) queue.add(temp.remove(0));
    return result;
}

// Return whether the stack is empty.
public boolean empty() {
    return queue.isEmpty();
}
}

/////
I use the 'popSize' to record the pop() so it's always O(1). Test if need to do 'compact' in every push or top call which can get O(1) in push or top in constantly push or top. It's an optimized to reduce constantly call However it performed not so good in LeetCode's test case :(

class MyStack {
    // Push element x onto stack.
    private LinkedList<Integer> list = new LinkedList<Integer>();
    private Integer TOP;
    private int popSize;
    public void push(int x) {
        if (popSize > 0) {
            compact();
        }

        TOP = new Integer(x);
        list.offer(TOP);
    }

    // Removes the element on top of the stack.
    public void pop() {
        //no need to do sanity check
        popSize++;
        TOP = Integer.MIN_VALUE; //make it invalid.
    }

    // Get the top element.
    public int top() {
        if (TOP == Integer.MIN_VALUE) {
            compact();
        }

        return TOP;
    }

    private void compact() {
        Integer tmp = null;
        int sz = list.size();
        for (int i = 0; i < sz; i++) {
            tmp = list.poll();
            if (i < sz - popSize) {
                list.offer(tmp);
                TOP = tmp;
            }
        }
        popSize = 0;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return list.size() == popSize;
    }
}
////
class MyStack {
    Queue<Integer> q = new LinkedList<Integer>();

    // Push element x onto stack.
    public void push(int x) {
        q.add(x);

        int n = q.size();
        while (n-- > 1)
            q.add(q.poll());
    }

    // Removes the element on top of the stack.
    public void pop() {
        q.poll();
    }

    // Get the top element.
    public int top() {
        return q.peek();
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q.isEmpty();
    }

  }
/////
class MyStack {

Queue<Integer> queue=new LinkedList<Integer>();
public void push(int x) {
    queue.offer(x);
    int i=queue.size()-1;
    while(i>0)
    {
        queue.offer(queue.poll());
        i--;
    }

}


public void pop() {
    queue.poll();
}


public int top() {
    return queue.peek();
}


public boolean empty() {
    return queue.isEmpty();

}
}
///
class MyStack {
    Queue<Integer> q = new LinkedList<>();
    Queue<Integer> tmp = new LinkedList<>();
    // Push element x onto stack.
    public void push(int x) {
        //pop elements in q into tmp
        while(!q.isEmpty()){
            tmp.offer(q.poll());
        }
        //add x into q
        q.offer(x);
        //pop elements in tmp into q
        while(!tmp.isEmpty()){
            q.offer(tmp.poll());
        }
    }

    // Removes the element on top of the stack.
    public void pop() {
        q.poll();
    }

    // Get the top element.
    public int top() {
        return q.peek();
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q.isEmpty();
    }
}
////
class MyStack {
    Queue<Integer> q = new LinkedList<Integer>();
    // Push element x onto stack.
    public void push(int x) {
        q.add(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.add(q.remove());    
        }
    }

    // Removes the element on top of the stack.
    public void pop() {
        q.remove();
    }

    // Get the top element.
    public int top() {
        return q.peek();
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q.isEmpty();
    }
}
////
The general idea is that we maintain the stack order in the queue.

Assuming the queue "queue" already contains the stack order of previous push. Then the next push(x) operation could be divided into steps:

We create a new queue "temp" and offer the value x to it.
Then we offer the values in "queue" into "temp"
We assign "queue" with "temp" (queue=temp)
In this way, the queue maintains the stack order again.

class MyStack {

private Queue<Integer> queue = new ArrayDeque<>();

// Push element x onto stack.
public void push(int x) {
    Queue<Integer> temp = new ArrayDeque<>();
    temp.offer(x);
    for (int i : queue) temp.offer(i);
    queue = temp;
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
/////
class MyStack {
    Queue<Integer> q = new LinkedList<Integer>();

    // Push element x onto stack.
    public void push(int x) {
        q.add(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
        int size = q.size();
        for(int i = 1; i < size; i++)
            q.add(q.remove());
        q.remove();
    }

    // Get the top element.
    public int top() {
        int size = q.size();
        for(int i = 1; i < size; i++)
            q.add(q.remove());
        int ret = q.remove();
        q.add(ret);
        return ret;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q.isEmpty();        
    }
}
