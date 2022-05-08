class MyQueue {
    
private:
    stack<int> stackA, stackB;
public:

    MyQueue() {
        
    }
    
    void push(int x) {
        if(stackA.empty() && stackB.empty()){
            stackA.push(x);
        }else if(stackB.empty()){
            while(!stackA.empty()){
                int temp = stackA.top();
                stackB.push(temp);
                stackA.pop();
            }
            stackA.push(x);
            while(!stackB.empty()){
                int temp = stackB.top();
                stackA.push(temp);
                stackB.pop();
            }
        }else if(stackA.empty()){  
            while(!stackB.empty()){
                int temp = stackB.top();
                stackA.push(temp);
                stackB.pop();                
            }
            stackB.push(x);
            while(!stackA.empty()){
                int temp = stackA.top();
                stackB.push(temp);
                stackA.pop();            
            }
         
        }
    }
    
    int pop() {
        if(!stackA.empty()){
            int temp = stackA.top();
            stackA.pop();
            return temp;
        }
        else{
            int temp = stackB.top();
            stackB.pop();
            return temp;        
        }
    }
    
    int peek() {
        if(!stackA.empty()){
            return stackA.top();
        }
        else{
            return stackB.top();
        }
  
    }
    
    bool empty() {
        return stackA.empty() && stackB.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */