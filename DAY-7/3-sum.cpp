// K-sum Problem O(N^2)
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
  // one for loop outside
  // two pointer approach inside
        for(int i=0;i<nums.size();i++)
        {
          // incase duplicates
             while(i>0 && i<nums.size()-1 && (nums[i] == nums[i-1]))
             {
                 i++;
             }
            int start = i+1,end = nums.size()-1;
            int target = -nums[i];
            while(start<end)
            {
                int sum = nums[start]+nums[end];
                if(sum == target)
                {
                    res.push_back({nums[i],nums[start],nums[end]});
                    while(start+1<end && nums[start] == nums[start+1])
                    {
                        start++;
                    }
                    while(start+1<end && end<nums.size() && nums[end] == nums[end-1])
                    {
                        end--;
                    }
                     start++;
                    end--;
                }
                else if(sum>target)
                    end--;
                else
                    start++;
            }
           
        }
        return res;
    }
