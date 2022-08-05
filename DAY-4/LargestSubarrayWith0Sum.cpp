int maxLen(vector<int>&A, int n)
    { 
  // to store possible sums
        unordered_map<int,int>mp;
        int ans = 0;
        int sum = 0;
        for(int i=0;i<A.size();i++)
        {
             sum += A[i];
          // if 0 found a subarray that starts from 0th index
             if(sum == 0)
             {
                 ans = i+1;
             }
            else
            {
              // if didn't found sum then push it in map
                if(mp.find(sum) == mp.end())
                {
                    mp[sum] = i;
                }
              // if found then there was a subarray that had 0 sum that's how we got same sum again
                else
                {
                    ans = max(ans,i-mp[sum]);
                }
            }
           
        }
        return ans;
    }
