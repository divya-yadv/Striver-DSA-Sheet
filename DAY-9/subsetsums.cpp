//O(2^N) + O(2^N*log(2^N))->if sorting required
// O(2^N)->no of subsets
void solve(vector<int> arr, int N, vector<int> &ans,int sum)
{
    if(N ==0)
    {
        ans.push_back(sum);
        return;
    }
  // we have two cases either we can include or not
    int sum1 = sum;
    int sum2 = sum + arr[N-1];
    solve(arr,N-1,ans,sum1);
    solve(arr,N-1,ans,sum2);
    
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(arr,N,ans,0);
        return ans;
    }


// iterative solution
vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        ans.push_back(0);
    // iterate over all elements
        for(int i=0;i<N;i++)
        {
            // add this to all elements that are already present in ans array, so that there will be both elements where you added the element and didn't add the element
            int p = ans.size();
           for(int j=0;j<p;j++)
           {
               ans.push_back(ans[j]+arr[i]);
           }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
