// O(2^t * k)

void solve(vector<int> candidates,int target, int i,vector<int>curr,vector<vector<int>>&res)
    {
        if(i == candidates.size())
        {
            return;
        }
        if(target == 0)
        {
            res.push_back(curr);
            return;
        }
  // consider two cases added or not added
        curr.push_back(candidates[i]);
        if(target >= candidates[i])
        {
            solve(candidates,target-candidates[i],i,curr,res);
        }
        curr.pop_back();
        solve(candidates,target,i+1,curr,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates,target,0,curr,res);
        return res;
    }
