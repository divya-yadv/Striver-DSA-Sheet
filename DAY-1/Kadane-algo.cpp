   
int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
          // incase of negative elements to see if we continue in the subarray or start a new subarray
            current_sum = max(current_sum+nums[i],nums[i]);
          // take the max
            max_sum = max(max_sum,current_sum);
        }
        return max_sum;
    }
};
