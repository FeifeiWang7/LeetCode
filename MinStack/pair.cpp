class MinStack {
    stack<pair<int, int>> st;

public:
    void push(int x) {
        int min;
        if (st.empty()) {
            min = x;
        }
        else {
            min = st.top().second<x? st.top().second:x;
        }
        pair<int, int>p(x, min);
        st.push(p);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
