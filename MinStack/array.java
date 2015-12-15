class MinStack {
    ArrayList<Integer> stack = new ArrayList<Integer>();
    //every node contains min value at the moment it was pushed
    ArrayList<Integer> min = new ArrayList<Integer>();
    //int l = stack.size()-1;
    int topv = 0;
    public void push(int x) {
        stack.add(x);
        if(min.size()==0) min.add(x);
        else if(x<min.get(min.size()-1)) min.add(x);
        else min.add(min.get(min.size()-1));
    }

    public void pop() {
        min.remove(min.size()-1);
        stack.remove(stack.size()-1);
    }

    public int top() {
        topv = stack.get(stack.size()-1);
        return topv;
    }

    public int getMin() {
        return min.get(min.size()-1);
    }
}
