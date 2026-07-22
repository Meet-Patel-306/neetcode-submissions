class MinStack {
public:
    stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> st2;
        int minv = INT_MAX;
        while(!st.empty()){
            minv = min(st.top(),minv);
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return minv;
    }
};
