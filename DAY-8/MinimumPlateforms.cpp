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

// check for the intervals that overlap the current one 
int findPlatform(int arr[], int dep[], int n)
{
 
    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
 
    // run a nested  loop to find overlap
    for (int i = 0; i < n; i++) {
        // minimum platform
        plat_needed = 1;
 
        for (int j = i + 1; j < n; j++) {
            // check for overlap
            if (max(arr[i], arr[j]) <= min(dep[i], dep[j]))
                plat_needed++;
        }
 
        // update result
        result = max(result, plat_needed);
    }
 
    return result;
}
