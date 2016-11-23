class MinStack {
    vector<int> diystack;
    vector<int> mini;//记录当前长度栈的最小值
    int t;
public:
    /** initialize your data structure here. */
    MinStack() {        
        diystack = vector<int>();
        t = -1;
    }
    
    void push(int x) {        //尤其要注意 pop后之后的向量更新，而不是直接push
        if(t<0||x<mini[t]){
            if(mini.size()>t+1){
                mini[t+1] = x;
            }else{
                mini.push_back(x);
            }
            
        }else{
            if(mini.size()>t+1){
                mini[t+1] = mini[t];
            }else{
                mini.push_back(mini[t]);
            }
            
        }
        if(diystack.size()>t+1){
            diystack[t+1] = x;
        }else{
            diystack.push_back(x);
        }       
        t++;
    }
    
    void pop() {
        t--;      
    }
    
    int top() {
        return diystack[t];
        
    }
    
    int getMin() {
        return mini[t];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */