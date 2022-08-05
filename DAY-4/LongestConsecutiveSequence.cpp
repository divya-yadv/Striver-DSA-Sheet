int longestConsecutive(vector<int>& nums) {
        int max_so_far = 0;
        int count = 0;
  // fill all numbers 
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
          // check if its a start of sequence
            if(st.find(nums[i]-1) == st.end())
            {
                int p = nums[i];
                count = 1;
              // get all that are in this sequence 
                while(st.find(p+1) != st.end())
                {
                    count++;
                    p++;
                }
                max_so_far = max(max_so_far,count);
            }
        }
        return max_so_far;
    }
