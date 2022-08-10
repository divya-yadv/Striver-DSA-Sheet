int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i=0,j=0,k=0;
        int ans = 0;
        while(i<n && j<n)
        {
          // as long as plateform is occupied
            if(arr[i] <= dep[j])
            {
                i++;
                k++;
            }
            else
            {
              // leave plateform 
                k--;
                j++;
            }
            ans = max(ans,k);
        }
        return ans;
    }
