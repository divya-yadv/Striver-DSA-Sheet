// O(N*logN)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>> minHeap;
        int i=0;
        while(i<nums.size())
        {
            minHeap.push(nums[i]);
            int n = minHeap.size();
            if(n > k)
            {
                minHeap.pop();
            }
            i++;
        }
        int ans = minHeap.top();
        return ans;
    }
/// we can use quicksort also in order to find kth largest element as we find position of pivot
