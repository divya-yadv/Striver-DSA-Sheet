// O(N * K * log K)
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    int n = kArrays.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push({kArrays[i][0],{i,0}});
    }
    while(pq.size())
    {
        pair<int,pair<int,int>>p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int array = p.second.first;
        int index = p.second.second;
        if((index+1) < kArrays[array].size())
        {
            pq.push({kArrays[array][index+1],{array,index+1}});
        }
    }
    return ans;
}
