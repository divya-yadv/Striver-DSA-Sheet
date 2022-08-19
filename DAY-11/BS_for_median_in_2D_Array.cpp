int Solution::findMedian(vector<vector<int> > &A) {
    int l = 0;
    int r = INT_MAX;
    int req = A.size()*A[0].size();
    while(r-l>1)
    {
        int mid = l+(r-l)/2;
        int cnt = 0;
      // count how many elements are greater than this mid in array
        for(auto &i:A)
        {
            int p = upper_bound(i.begin(),i.end(),mid)-i.begin();
            cnt += p;
        }
        if(cnt >= (req/2+1))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}
