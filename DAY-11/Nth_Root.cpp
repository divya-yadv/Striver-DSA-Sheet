// to calculate mid power n
//N x log(M x 10^d)
long double nthpow(long double mid,int n)
{
    long double ans = 1.0;
    while(n--)
        ans *= mid;
    return ans;
}
long double findNthRootOfM(int n, long long m) {
  // will use BS to find number which is x^n = m
   long double l = 1.0;
    long double r =(long double) m;
    long double e = 1e-9;
    while((r-l) > e)
    {
        long double mid = l+(r-l)/2.0;
        if(nthpow(mid,n) > (long double)m)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}
