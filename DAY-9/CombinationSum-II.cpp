// O(2^n)
// O(x*k) -> k combinations with x average length
void solve(vector<int>&candidates,int target,int i,vector<vector<int>>&res,vector<int>&v)
    {
  // add to solution
        if(target == 0)
        {
            res.push_back(v);
            return;
        }
  // here we are trying to fix ith element
        for(int j=i;j<candidates.size();j++)
        {
          // same value shouldn't get fixed at same position 
            if(j > i && candidates[j] == candidates[j-1])
            {
                continue;
            }
          // sorted, so no need to go further
            if(candidates[j] > target)
            {
                break;
            }
          // add to solution array and move to next position 
            v.push_back(candidates[j]);
            solve(candidates,target-candidates[j],j+1,res,v);
          // pop_back in case of no solution
            v.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        solve(candidates,target,0,res,v);
        return res;
    }
