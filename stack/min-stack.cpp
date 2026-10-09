class MinStack {
public:
    stack<long long> st;
    long long mini;
    
    MinStack() {
        // Initialize the stack and mini
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        long long value = val;  // Convert val to long long to handle large values
        if (st.empty()) {
            mini = value;  // First element will be the minimum
            st.push(value);  // Push the value as it is
        } else {
            if (value < mini) {
                st.push(2 * value - mini);  // Store modified value
                mini = value;  // Update the minimum
            } else {
                st.push(value);  // Push the value normally
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        
        long long el = st.top();
        st.pop();
        
        // If the popped element is less than mini, update mini
        if (el < mini) {
            mini = 2 * mini - el;  // Restore the previous minimum
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        
        long long el = st.top();
        if (el < mini) {
            return mini;  // The top element is a modified value, return mini
        }
        
        return el;  // Normal value
    }
    
    int getMin() {
        return mini;
    }
};
