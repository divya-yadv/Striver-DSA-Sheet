
int removeDuplicates(vector<int>& nums) {
        int last = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[last])
            {
                last++;
                nums[last] = nums[i];
            }
        }
        return last+1;
    }
