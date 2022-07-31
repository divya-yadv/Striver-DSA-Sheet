   void sortColors(vector<int>& nums) {
        int end = nums.size()-1;
        int start = 0;
        int i=0;
        while(i<=end)
        {
            if(nums[i] == 2)
            {
                swap(nums[i],nums[end]);
                end--;
            }
            else if(nums[i] == 0)
            {
                swap(nums[i],nums[start]);
                start++;
                i++;
            }
            else
            {
                i++;
            }
        }
    }
