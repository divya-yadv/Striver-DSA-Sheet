//O(n*m), O(n*m) 
int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n, 1));
       for(int i=1;i<m;i++)
       {
           for(int j=1;j<n;j++)
           {
               dp[i][j] = dp[i-1][j]+dp[i][j-1];
           }
       }
        return dp[m-1][n-1];
    }

// as we can see here we only need previous row not the whole matrix
// we can optimize it more
int uniquePaths(int m, int n) {
      vector<int>prev(n,1);
       for(int i=1;i<m;i++)
       {
           vector<int>curr(n,1);
           for(int j=1;j<n;j++)
           {
               curr[j] = prev[j]+curr[j-1];
           }
           prev=curr;
       }
        return prev[n-1];
    }

// if we don't swap curr and prev we have curr values in prev and we can update there only
int uniquePaths(int m, int n) {
      vector<int>prev(n,1);
       for(int i=1;i<m;i++)
       {
           for(int j=1;j<n;j++)
           {
               prev[j] = prev[j]+prev[j-1];
           }
       }
        return prev[n-1];
    }

// this is also a combination process m-1 steps down and n-1 steps right find combination (m+n)!/m!*n!, just maken sure interger doesn't overflow
