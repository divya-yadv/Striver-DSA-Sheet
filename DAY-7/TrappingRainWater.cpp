// O(N),O(N)
 int trap(vector<int>& height) {
        int n = height.size();
        int larr[n];
        int rarr[n];
        larr[0] = height[0];
        rarr[n-1] = height[n-1];
        for(int i=1;i<n;i++)
        {
            larr[i] = max(larr[i-1],height[i]);
        }
         for(int i=n-2;i>=0;i--)
        {
            rarr[i] = max(rarr[i+1],height[i]);
        }
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            ans += min(larr[i],rarr[i])-height[i];
        }
        return ans; 
    }


// O(N),O(1)

