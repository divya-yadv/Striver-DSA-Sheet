// sort and find indexes nlogn+n+n, O(N)
vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> temp;
        temp = nums;
        sort(temp.begin(),temp.end());
        int start = 0;
        int end = nums.size()-1;
        while(start<end)
        {
            if((temp[start]+temp[end]) == target)
                break;
            else if(temp[start]+temp[end] > target)
                end--;
            else
                start++;
        }
        int first = -1;
        int last = -1;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i] == temp[start] && first == -1)
           {
               first = i;
           }
           else if(nums[i] == temp[end] && last == -1)
           {
               last= i;
           }
       }
        return {first,last};
    }


// using a map
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
          int s = target-nums[i];
        // see if second element is present in map
        // else store element and index
          if(mp.find(s) != mp.end())
          {
              return {mp[s],i};
          }
          else
          {
              mp[nums[i]] = i;
          }
      }
        return {-1,-1};
    }


