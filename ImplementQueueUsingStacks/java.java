class MyQueue {
private Stack<Integer> stack = new Stack<>();

// Push element x to the back of queue.
public void push(int x) {
    Stack<Integer> tmp = new Stack<>();
    int len = stack.size();
    for (int i = 0; i < len; i++) {
        tmp.push(stack.peek());
        stack.pop();
    }
    stack.add(x);
    for (int i = 0; i < len; i++) {
        stack.add(tmp.peek());
        tmp.pop();
    }
}

// Removes the element from in front of queue.
public void pop() {
    if (stack != null) stack.pop();
}

// Get the front element.
public int peek() {
    return (Integer) stack.peek();
}

// Return whether the queue is empty.
public boolean empty() {
    return stack == null ? true : stack.isEmpty();
}
}

///
class MyQueue {
    Stack<Integer> pushStack = new Stack<>();
    Stack<Integer> popStack = new Stack<>();

    // Push element x to the back of queue.
    public void push(int x) {
        pushStack.push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        if(popStack.isEmpty()) {
            while(!pushStack.isEmpty()) {
                popStack.push(pushStack.pop());
            }
        }
        popStack.pop();
    }

    // Get the front element.
    public int peek() {
        if(popStack.isEmpty()) {
            while(!pushStack.isEmpty()) {
                popStack.push(pushStack.pop());
            }
        }
        return popStack.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return pushStack.isEmpty() && popStack.isEmpty();
    }
}
///
class MyQueue {
private Stack<Integer> frontStack = new Stack<>();
private Stack<Integer> backStack = new Stack<>();

// Push element x to the back of queue.
public void push(int x) {
    backStack.push(x);
}

// Removes the element from in front of queue.
public void pop() {
    if(frontStack.isEmpty()){
        while(!backStack.isEmpty()){
            frontStack.push(backStack.pop());
        }
    }

    frontStack.pop();

}

// Get the front element.
public int peek() {
    if(frontStack.isEmpty()){
        while(!backStack.isEmpty()){
            frontStack.push(backStack.pop());
        }
    }
    return frontStack.peek();

}

// Return whether the queue is empty.
public boolean empty() {
    if(frontStack.isEmpty() && backStack.isEmpty()) return true;
    else return false;
}
}

///
private Stack<Integer> stack = new Stack<>();

private Stack<Integer> stack2 = new Stack<>();

// Push element x to the back of queue.
public void push(int x) {
    while (!stack2.isEmpty()) {
        stack.push(stack2.pop());
    }
    stack.push(x);
}

// Removes the element from in front of queue.
public void pop() {
    while (!stack.isEmpty()) {
        stack2.push(stack.pop());
    }
    stack2.pop();
}

// Get the front element.
public int peek() {
    while (!stack.isEmpty()) {
        stack2.push(stack.pop());
    }
    return stack2.peek();
}

// Return whether the queue is empty.
public boolean empty() {
    return stack.isEmpty() && stack2.isEmpty();
}
///
import java.util.*;
class MyQueue {
    Stack<Integer> stack = new Stack<>();
    // Push element x to the back of queue.
    public void push(int x) {
        Stack<Integer> stackAuxi = new Stack<>();
        while(!stack.isEmpty()) {
            stackAuxi.push(stack.pop());
        }
        stack.push(x);
        while(!stackAuxi.isEmpty()) {
            stack.push(stackAuxi.pop());
        }
    }

    // Removes the element from in front of queue.
    public void pop() {
        stack.pop();
    }

    // Get the front element.
    public int peek() {
        return stack.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return stack.isEmpty();
    }
}
///
class MyQueue {

    Stack<Integer> s1 = new Stack();
    Stack<Integer> s2 = new Stack();

    // Push element x to the back of queue.
    public void push(int x) {
      while (!s2.isEmpty())
        s1.push(s2.pop());

      s1.push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
      while (!s1.isEmpty())
        s2.push(s1.pop());

      s2.pop();
    }

    // Get the front element.
    public int peek() {
      while (!s1.isEmpty())
        s2.push(s1.pop());

      return s2.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
      return s1.isEmpty() && s2.isEmpty();
    }

  }
//
class MyQueue {
    Stack<Integer> in = new Stack<>();
    Stack<Integer> out = new Stack<>();
    // Push element x to the back of queue.
    public void push(int x) {
        in.push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        if(out.isEmpty()){
            queueing();
        }
        if(out.isEmpty())
            return;

        out.pop();
    }

    // Get the front element.
    public int peek() {
        if(out.isEmpty()){
            queueing();
        }
        return out.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return in.isEmpty() && out.isEmpty();
    }

    private void queueing(){
        if(out.isEmpty()){
           while(!in.isEmpty()){
               out.push(in.pop());
           } 
        }
    }

}
The only time you need to push data from in stack to out stack is when the out stack is empty. No need to pull everything from in stack every time and push them back once the pop or peek is done.
///
class MyQueue {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
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
}
