////
public class MinStack {
    private readonly Stack<long> stack = new Stack<long>();
    private long min = 0l;
    public void Push(int x){
        stack.Push((long)x - (min = stack.Count == 0 ? (long)x : min));
        if ((long)x < min) min = (long)x;
    }
    public void Pop(){
        if(stack.Peek() < 0) min -= stack.Peek();
        stack.Pop();
    }
    public int Top(){
        return stack.Peek() < 0 ? (int)min : (int)(min + stack.Peek());
    }
    public int GetMin(){
        return (int)min;
    }
}
///
class MinStack { int min; ArrayList ar; ArrayList minList; HashMap<Integer,Integer> map;

MinStack() {
    min = Integer.MAX_VALUE;
    ar = new ArrayList<Integer>();
    minList = new ArrayList<Integer>(); 
    map = new HashMap<Integer,Integer>();
}

public void push(int x) {
    if (min >= x) {
        min = x;

        if (map.containsKey(x)) {
            int count = map.get(x);
            map.put(x,count+1);
        }
        else {
            minList.add(x);
            map.put(x,1);
        }
    }
    ar.add(x);
}

public void pop() {
    int top = this.top();

    if (top == min) {
        int count = map.get(min);
        if (count > 1) {
            map.put(min, count - 1);
        }
        else {
            map.remove(min);
            minList.remove(minList.size()-1);
            if(minList.size() > 0) {
                min = minList.get(minList.size()-1);
            }
            else {
                min = Integer.MAX_VALUE;
            }
        }
    }
    ar.remove(ar.size()-1);
}

public int top() {
    return ar.get(ar.size()-1);
}

public int getMin() {
    return min;
}
}
///
class MinStack {

private Stack<Integer> stack = new Stack<Integer>();
private Stack<Integer> minStack = new Stack<Integer>();


public void push(int x) {
    stack.push(x);
    if(minStack.isEmpty() || x <= minStack.peek()){
        minStack.push(x);
    }
}

public void pop() {
    if(stack.isEmpty()){
        return;
    }
    int x = stack.peek();
    if(!minStack.isEmpty() && x == minStack.peek()){
        minStack.pop();
    }
    stack.pop();
}

public int top() {
    return stack.peek();
}

public int getMin() {
    if(minStack.isEmpty()){
        return 0;
    }
    return minStack.peek();
}
}
