class MinStack {
    stack<long long> st;
    long long mini = LLONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
        if(val > mini) st.push(val);
        else{
            st.push(2*val - mini);
            mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini){
            mini = 2*mini - x;
        }
    }
    
    int top() {

        long long x = st.top();
        if(mini < x) return x;

        return mini;
    }
    
    int getMin() {
        return mini;
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