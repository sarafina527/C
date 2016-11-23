class Queue {
    stack<int> head = stack<int>();
    stack<int> tail = stack<int>();
public:
    // Push element x to the back of queue.
    void push(int x) {
        tail.push(x);
        stack<int> tmp = stack<int>();
        while(!head.empty()){
            tmp.push(head.top());
            head.pop();
            
        }
        tmp.push(x);
        while(!tmp.empty()){
            head.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        head.pop();
        stack<int> tmp = stack<int>();
        while(!tail.empty()){
            tmp.push(tail.top());
            tail.pop();            
        }
        tmp.pop();
        while(!tmp.empty()){
            tail.push(tmp.top());
            tmp.pop();
        }

    }

    // Get the front element.
    int peek(void) {
        return head.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(head.empty()){
            return 1;
        }else{
            return 0;
        }
    }
};