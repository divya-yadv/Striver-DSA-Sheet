// O(N*N) N-> for pushing v to res
// O(N!)
bool isSafe(int row, int col,int n, vector<string>v)
    {
        // same column
       for(int k=0;k<=row;k++)
       {
          if(v[k][col] == 'Q')
          {
              return false;
          }
       }
        // left diagonal
         // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(v[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<n;--i,++j)
            if(v[i][j] == 'Q') return false;
       return true;
    }
    void solve(int n, int i, vector<string>&v,vector<vector<string>>&res)
    {
      // all placed
        if(i == n)
        {
            res.push_back(v);
            return;
        }
      // check for every column in every row
        for(int j=0;j<n;j++)
        {
          // if safe
            if(isSafe(i,j,n,v))
            {
              // place queen
                v[i][j] = 'Q';
                solve(n,i+1,v,res);
                v[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> v;
        string s(n, '.');
        for(int i=0;i<n;i++)
        {
            v.push_back(s);
        }
        solve(n,0,v,res);
        return res;
    }
