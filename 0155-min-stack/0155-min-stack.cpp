class MinStack {
public:
    
    vector<int> st, ind;
    MinStack() {
        
    }
    
    void push(int val) {
        if(ind.empty() || val < st[ind.back()]) ind.push_back(st.size());
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        if(st.size() == ind.back()) ind.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return st[ind.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */