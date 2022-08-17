// O(9^(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
bool isSafe(vector<vector<char>>& board,int row,int col,char value)
    {
        for(int i=0;i<9;i++)
        {
            // same column or same column
            if(board[row][i] == value || board[i][col] == value )
            {
                return false;
            }
        }
  // first box second box third box three rows of 3*3 
        int srow = row-row%3;
  // same for column
        int scol = col-col%3;
        // check for inner grid
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[srow+i][scol+j]== value)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
      // check if anyone need to be updated
        bool flag = false;
        int row = 0;
        int col = 0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
               if(board[i][j] == '.')
               {
                   flag = true;
                   row = i;
                   col = j;
                   break;
               }
            }
            if(flag)
            {
                break;
            }
           
        }
        if(!flag)
       {
          return true;
       }
       for(int val=1;val<=9;val++)
       {
         // check for values from 1 to 9
           if(isSafe(board,row,col,val+'0'))
           {
               board[row][col] = val+'0';
               if(solve(board))
               {
                   return true;
               }
               board[row][col] = '.';
           }
       }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
       bool ans = solve(board);
        return;
    }
