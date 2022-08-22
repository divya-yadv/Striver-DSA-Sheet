class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    int size;
    MyQueue() {
        size=0;
    }
    
    void push(int x) {
        st1.push(x);
        size++;
    }
    
    int pop() {
        if(size == 0)
        {
            return -1;
        }
        while(st1.size() != 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();
        st1.pop();
        while(st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        size--;
        return ans;
    }
    
    int peek() {
        if(size == 0)
        {
            return -1;
        }
        while(st1.size() != 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();
        while(st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
