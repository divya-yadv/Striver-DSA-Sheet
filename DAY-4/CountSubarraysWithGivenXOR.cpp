
int subarraysXor(vector<int> &arr, int x)
{
    map<int,int>mp;
    int xr = 0;
    int count = 0;
    for(int i=0;i<arr.size();i++)
    {
      // xor od elements from index 0 to i
        xr ^= arr[i];
      // if equal to given xor then count++
        if(xr == x)
        {
            count++;
        }
      // if we find a subarray that has XOR thats equal to B we add this and count how many subarrays are there with xor that can give us B.
        if(mp.find(xr^x) != mp.end())
        {
            count += mp[xr^x];
        }
        mp[xr]++;
    }
    return count;
}
