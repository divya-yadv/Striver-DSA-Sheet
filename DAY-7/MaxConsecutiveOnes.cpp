
int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_l = 0;
        int curr = 0;
        for(int i=0;i<nums.size();i++)
        {
          // if consecutive
            if(nums[i] == 1)
            {
                curr++;
                max_l = max(curr,max_l);
            }
            else
            {
                curr = 0;
            }
           
        }
        return max_l;
    }
