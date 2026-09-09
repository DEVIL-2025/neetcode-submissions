class MinStack {
    stack<int> s;
    stack<int> s1;
public:
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini= min(val, mini);
        s.push(val);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        if(top == mini){
            mini = INT_MAX;
            while(!s.empty()){
                int top = s.top();
                mini = min(mini, top);
                s.pop();
                s1.push(top);
            }
            while(!s1.empty()){
                int top = s1.top();
                s1.pop();
                s.push(top);
            }
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini;
    }
};
