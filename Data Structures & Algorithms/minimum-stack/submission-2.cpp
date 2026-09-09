class MinStack {
    stack<int> s;
    stack<int> minStack;
    int mini = INT_MAX;
public:
    MinStack() {
        
    }  
    void push(int val) {
        mini = min(val, mini);
        minStack.push(mini);
        s.push(val);
    }
    
    void pop() {
        s.pop();
        minStack.pop();
        if(!minStack.empty()){
            mini = minStack.top();
        }
        else{
            mini = INT_MAX;
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
