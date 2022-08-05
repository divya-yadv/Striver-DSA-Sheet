vector<vector<int>> fourSum(vector<int>& nums, int target) {
  // sort this
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        int n = nums.size();
        if(n<4)
        {
            return v;
        }
  // fix two pointers for two numbers
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)    
           {
               
            long long int sum = nums[i]+nums[j];
            int start = j+1,end= n-1;
             // use two pointer approach to find two other ones
            while(start<end)
            {
               long long int sum2 = sum+nums[start]+nums[end];
                if(sum2 == target)
                {
                    vector<int> p = {nums[i],nums[j],nums[start],nums[end]};
                    v.push_back(p);
                  // take care of duplicates for all 4
                    while(start < end && nums[start] == p[2]) ++start;
                    while(start < end && nums[end] == p[3]) --end;
                }
                else if(sum2 > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
               while(j+1<n && nums[j+1] == nums[j]) j++;
          }
            while(i+1<n && nums[i+1] == nums[i]) i++;
       }
        return v;
    }
