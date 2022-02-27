class MinStack {
public:
       
    stack<pair<int, int>> myStack;
    MinStack() {
        
    }
    
void  push(int val) {
    
       if(!myStack.empty()){
           int min = myStack.top().second;
           int newMin= val < min ? val : min; 
           myStack.push(make_pair(val, newMin));
        }else{
           myStack.push(make_pair(val, val));

       }
      

        
        
}
void pop() {
        if(!myStack.empty()){
            myStack.pop();
        }
      

}
int top() {
        if(!myStack.empty()){
            return myStack.top().first;
        }
        return 0;
}
int getMin() {
    if(!myStack.empty()){
            return myStack.top().second;
        }
        return 0;
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