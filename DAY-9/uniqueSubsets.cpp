// TC- > O(2^N * k* log( x)  to insert every combination of average length k in a set of size x. )
// SC -> 2*O(2^N*k)

void solve(vector<int>nums,set<vector<int>>&st,int i,vector<int> curr)
    {
        if(i == nums.size())
        {
            sort(curr.begin(),curr.end());
            st.insert(curr);
            return;
        }
  // consider both cases adding or not adding
        solve(nums,st,i+1,curr);
        curr.push_back(nums[i]);
        solve(nums,st,i+1,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      // store them in a set
        set<vector<int>> st;
        vector<int>curr;
        solve(nums,st,0,curr);
        vector<vector<int>> s;
        for(auto v:st)
        {
            s.push_back(v);
        }
        return s;
    }

// we can optimize it by storing only unique sets without using set data structure 

void solve(vector<int>nums,vector<vector<int>>&st,int i,vector<int>& curr)
    {
  // we have one subset 
       st.push_back(curr);
  // for every index we will check if there are duplicates
        for(int j=i;j<nums.size();j++)
        {
          // skip middle elements
            if(j!=i && nums[j] == nums[j-1])
            {
                continue;
            }
          // push this to our new subset
            curr.push_back(nums[j]);
          // call function for next index now
            solve(nums,st,j+1,curr);
          // incase we don't want to add this elements
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>> st;
      // sort to get duplicates together
        sort(nums.begin(),nums.end());
        solve(nums,st,0,curr);
        return st;
    }
