// 4^(m*n)
// O(m*n)
bool isSafe(vector<vector<int>>m,int i, int j,int n)
    {
        if((i<n )&& (i>=0) && (j<n) && (j>=0) && (m[i][j] == 1))
        {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>>&m,int n,int i,int j,vector<string>&res,string s)
    {
        if((i == n-1) && (j ==n-1) )
        {
            res.push_back(s);
            return;
        }
      // check safe for all directions
        if(isSafe(m,i+1,j,n))
        {
          // single cell should be included only once in the path,so it’s important to keep track of the visited cells in a particular path
            m[i][j] = 2;
            solve(m,n,i+1,j,res,s+'D');
            m[i][j] = 1;
        }
         if(isSafe(m,i,j-1,n))
        {
             m[i][j] = 2;
            solve(m,n,i,j-1,res,s+'L');
             m[i][j] = 1;
        }
         if(isSafe(m,i,j+1,n))
        {
             m[i][j] = 2;
            solve(m,n,i,j+1,res,s+'R');
             m[i][j] = 1;
        }
         if(isSafe(m,i-1,j,n))
        {
             m[i][j] = 2;
             solve(m,n,i-1,j,res,s+'U');
             m[i][j] = 1;
        }
       
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
         {
             return res;
         }
         string p="";
        solve(m,n,0,0,res,p);
        
        return res;
    }
