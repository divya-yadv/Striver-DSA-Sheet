// storing at the first row and col is that whole should be zero or not
void setZeroes(vector<vector<int>>& matrix) {
        bool isRowZero = false;
        bool isColZero = false;
        
        for(int row=0;row<matrix.size();row++)
        {
            for(int col=0;col<matrix[0].size();col++)
            {
                int val = matrix[row][col];
                if(val==0)
                {
                    if(row == 0)
                    {
                        isRowZero = true;
                    }
                    if(col == 0)
                    {
                        isColZero = true;
                    }
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
                
            }
        }
        for(int row=1;row<matrix.size();row++)
        {
            if(matrix[row][0] == 0)
            {
                for(int col=0;col<matrix[0].size();col++)
                {
                
                    matrix[row][col] = 0;
               }
            }
        }
        for(int col=1;col<matrix[0].size();col++)
        {
            if(matrix[0][col] == 0)
            {
                for(int row=0;row<matrix.size();row++)
                {
                
                    matrix[row][col] = 0;
               }
            }
        }
        if(isRowZero)
        {
             for(int col=0;col<matrix[0].size();col++)
                {
                
                    matrix[0][col] = 0;
               }
        }
        if(isColZero)
        {
              for(int row=0;row<matrix.size();row++)
                {
                
                    matrix[row][0] = 0;
               }
        }
    }
