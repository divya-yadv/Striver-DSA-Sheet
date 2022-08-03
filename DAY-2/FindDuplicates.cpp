int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
          // that means if we have added same element before, value is greater than n == nums[i]+n;
            if(nums[nums[i]%n] > n)
                return nums[i]%n;
            nums[nums[i]%n] += n;
        }
        return -1;
    }
