// aaditya verma
int isValid(vector<int>arr,int mid,int n,int k)
{
     int students=1;
     int sum=0;
     for(int i=0;i<n;i++)
     {
         if((sum + arr[i]) > mid)
         {
            students++;
             sum = arr[i];
            if(sum>mid)
            {
                 return false;
            }
         }
        else{
            sum += arr[i];
        }
     }
     if(students>k)
     {
         return false;
     }
     return true;
}
int Solution::books(vector<int> &A, int B) {
    if(A.size()<B)
    {
        return -1;
    }
    int low = A[0];
    int high = 0;
    for(int i=0;i<A.size();i++)
    {
        low = max(low,A[i]);
        high += A[i];
    }
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(isValid(A,mid,A.size(),B))
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}
