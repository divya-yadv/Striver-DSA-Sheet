int lps(string pat)
{
    int n = pat.length();
    int lps[n];
    lps[0] = 0;
    int len = 0;
    int i=1;
    while(i<n)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len == 0){
                lps[i] = 0;
               i++;
               
            }
            else
            {
                len = lps[len-1];
            }
        }
    }
    return lps[n-1];
}
int Solution::solve(string A) {
    int n = A.length();
    string B = A;
    reverse(A.begin(),A.end());
    string pat = B+'#'+A;
  // int this string how many characters matches with last tells us how many are already making palindrome
    int ans = lps(pat);
    return n-ans;
}
