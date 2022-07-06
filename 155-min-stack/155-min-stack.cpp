class MinStack {
public:
    
    // data members
    stack<long> s;
    long mini = INT_MAX;
    
    MinStack() {

    }
    
    void push(long val) {
           
        if(s.empty()){
            s.push(val);
            mini = val;
        }
        else{
            
            // if value is smaller than mini
            // we need to change value to keep track of prev mini
            if(val < mini){   
                s.push(2*val - mini);
                mini = val; 
            }
            
            // if value is greater than mini
            // no change
            else{    
                s.push(val);
            }
        }
    }
    
    void pop() {
        
        // if value is greater than mini
        // no change
        if(s.top() >= mini){
            s.pop();
        }
        
        // if value is smaller than mini
        // change mini to prev mini
        else{
            mini = 2*mini - s.top();
            s.pop();
        }
    }
    
    int top() {
        
        if(s.top() >= mini){
            return s.top();
        }
        else{
            return mini;
        }
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