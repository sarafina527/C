class Stack {
    queue<int> shun = queue<int>();
    queue<int> ni = queue<int>();
public:
    // Push element x onto stack.
    void push(int x) {
        shun.push(x);
        //处理逆序队列
        queue<int> tmp = queue<int>();
        while(!ni.empty()){
            tmp.push(ni.front());
            ni.pop();
        }
        ni.push(x);
        while(!tmp.empty()){
            ni.push(tmp.front());
            tmp.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        ni.pop();
        int cnt = 0;
        queue<int> tmp = queue<int>();
        while(!shun.empty()){
            tmp.push(shun.front());
            shun.pop();
            cnt++;
        }
        for(int i=0;i<cnt-1;i++){
            shun.push(tmp.front());
            tmp.pop();
        }
    }

    // Get the top element.
    int top() {
        return ni.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        if(shun.empty()){
            return 1;
        }else{
            return 0;
        }
    }
};