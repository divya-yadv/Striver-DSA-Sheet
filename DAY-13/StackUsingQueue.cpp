class MyStack {
    private:
            queue<int>q1;
            queue<int>q2;
            int size;
public:
    MyStack() {
        size=0;
    }
    // O(1)
    void push(int x) {
        q1.push(x);
        size++;
    }
    
  // O(n)
    int pop() {
        if(size == 0)
        {
            return -1;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans= q1.front();
        q1.pop();
        while(q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        size--;
        return ans;
    }
    
  // O(1)
    int top() {
        if(size == 0)
        {
            return -1;
        }
        return q1.back();
        
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
