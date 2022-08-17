// O(m^n) -> m color can be assigned to n nodes
bool isSafe(bool graph[101][101], int color[],int k,int i,int n)
     {
  // in color array
         for(int j=0;j<n;j++)
         {
           // see if there is any adjcent to this node that has been assigned the same color
             if(j != i && graph[i][j] == 1 && color[j] == k)
             {
                 return false;
             }
         }
         return true;
     }
     bool coloring(bool graph[101][101],int color[], int m,int i, int n)
     {
       //if successfully assigned to all return true
         if(i == n )
         {
             return true;
         }
       // assign every color to every node
         for(int k=1;k<=m;k++)
         {
             color[i] = k;
           // see if color is safe to assign
             if(isSafe(graph,color,k,i,n))
             {
               // also see if by assigning this color we get the solution 
                 if(coloring(graph,color,m,i+1,n)){
                     return true;
                 }
                 
             }
           // backtrack coz we didn't get
             color[i] = 0;
         }
         return false;
     }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
      // assign color 0 to every node (no color)
        int color[n] = {0};
        return coloring(graph,color,m,0,n);
    }
