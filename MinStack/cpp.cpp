///
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())  s2.push(x);       
    }
    void pop() {
        if (s1.top() == getMin())  s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top();
    }
};
////
class MinStack {
    // a vector of (val, mininal_val) 
    std::vector<std::pair<int, int>>  data;

public:
    void push(int x) {
        int min_val = data.empty() ? x : (std::min(getMin(), x));
        data.push_back(std::make_pair(x, min_val));
    }

    void pop() {
        assert(!data.empty());
        data.pop_back();
    }

    int top() {
        assert(!data.empty());
        return data.back().first;
    }

    int getMin() {
        assert(!data.empty());
        return data.back().second;
    }
};
////////

class MinStack { public:

stack<int> Data, Min;

void push(int x) {
    Data.push(x);
    if(Min.empty()||x<Min.top()) Min.push(x);
    else Min.push(Min.top());
}

void pop() {
    if(Data.empty()) return;
    Data.pop();
    Min.pop();
}

int top() {
    if(!Data.empty())
        return Data.top();
}

int getMin() {
    if(!Min.empty());
        return Min.top();
}
};
/////////////
class MinStack {
public:
    vector<int> stack; 
    vector<int> stmin = {INT_MAX};
    void push(int x) {
        if(x <= stmin[stmin.size() - 1]) stmin.push_back(x);
        stack.push_back(x);
    }

    void pop() {
        if(stack[stack.size() - 1] == stmin[stmin.size() - 1]) stmin.pop_back();
        stack.pop_back();
    }

    int top() {
        if(stack.size() == 0) return 0;
        return stack[stack.size() - 1];
    }

    int getMin() {
        return stmin[stmin.size() - 1];
    }
};
