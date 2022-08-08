
int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_l = 0;
        int curr = 0;
        if(nums[0] == 1)
        {
            max_l =1;
            curr = 1;
        }
        for(int i=1;i<nums.size();i++)
        {
          // if consecutive
            if((nums[i] == 1 )&& (nums[i] == nums[i-1]))
            {
                curr++;
                max_l = max(curr,max_l);
            }
          // if started
            else if(nums[i] == 1)
            {
                curr = 1;
                max_l = max(curr,max_l);
            }
            else
            {
                curr = 0;
            }
        }
        return max_l;
    }
