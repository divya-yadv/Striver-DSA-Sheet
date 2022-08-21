// O((N-k)*logk)
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
int partition(vector<int>& nums,int left,int right){
	int pivot = nums[left], l=left+1, r = right;
	while(l<=r){
		if(nums[l]<pivot && nums[r]>pivot) swap(nums[l++],nums[r--]);
		if(nums[l]>=pivot) ++l;
		if(nums[r]<=pivot) --r;
	}
	swap(nums[left], nums[r]);
	return r;
}
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size()-1;
        int p=0;
        while(1)
        {
            p = partition(nums,l,r);
            if(p == (k-1))
            {
                break;
            }
             else if(p<k-1)
            {
                l = p+1;
            }
           else
           {
               r = p-1;
           }
        }
        return nums[p];
    }
