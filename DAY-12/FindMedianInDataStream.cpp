// have two heaps to store both parts 
priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
     int n=0;
    MedianFinder() {
       
    }
// O(logN)
    void addNum(int num) {
        if(maxheap.size() == 0)
        {
            maxheap.push(num);
        }
        else if(minheap.size() == 0)
        {
            if(maxheap.top() > num)
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
            else
                minheap.push(num);
        }
        else
        {
            if(num > minheap.top())
            {
                minheap.push(num);
            }
            else 
            {
                maxheap.push(num);
            }
        }
        if(maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if(minheap.size() < maxheap.size()-1)
        {
             minheap.push(maxheap.top());
             maxheap.pop();
        }
        n++;
    }
    
    double findMedian() {
        if((n%2) == 0)
        {
            int sum = maxheap.top()+minheap.top();
            return sum/2.0;
        }
        else
        {
            return maxheap.top();
        }
    }
