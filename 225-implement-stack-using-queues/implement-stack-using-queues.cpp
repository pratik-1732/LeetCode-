class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        int size= q.size();
        cout<<x<<" "<<size<<endl;
        if(size==0) {
            q.push(x);
            return;
        }
        q.push(x);
        for(int i=0; i<size; i++){
            int top= q.front();
            // cout<<top<<" ";
            q.push(top);
            q.pop();
        }
    }
    
    int pop() {
        int ele= q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */