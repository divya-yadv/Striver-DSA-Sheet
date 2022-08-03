 vector<vector<int>> merge(vector<vector<int>>& intervals) {
   //sort first
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        if(intervals.size() == 0)
        {
            return res;
        }
   // fill first interval
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            int n = res.size();
          // can't be merged
            if(res[n-1][1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
          // merge and make it one
            else
            {
                res[n-1][1] = max(res[n-1][1],intervals[i][1]);
            }
        }
        return res;
    }
