// O(N log N) + O(N*M) M-> max deadline
// O(M)
static bool mycomp(Job n1, Job n2)
    {
        return n1.profit>n2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
      // sort according to profit
        sort(arr,arr+n,mycomp);
        int size = 0;
        int maxprofit = 0;
        int t=0;
      // get max deadline
        for(int i=0;i<n;i++)
        {
            t = max(t,arr[i].dead);
        }
        // make a deadline array to see if there is any slot empty to fill this activity
        vector<int> deadline(t+1,-1);
        
        for(int i=0;i<n;i++)
        {
          // search slot in activity array
            for(int j=arr[i].dead;j>0;j--)
            {
              // if found slot add the profit
                if(deadline[j] == -1)
                {
                    size++;
                    deadline[j] = arr[j].id;
                    maxprofit += arr[i].profit;
                    break;
                }
            }
        }
        return {size,maxprofit};
    } 
