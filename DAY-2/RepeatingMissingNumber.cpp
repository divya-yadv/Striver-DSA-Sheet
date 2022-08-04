vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int ans1 = 0;
    int ans2 = 0;
    int xorall = 0;
    int n = a.size();
    for(int i=1;i<=n;i++)
    {
        xorall ^= i;
        xorall ^= a[i-1];
    }
  // get the xor of everything in order to achieve xor of both required numbers
  // now wee have to separate them
  // make pool of two numbers both will be in different pools coz 1+0 = 1
  // get lastsetbit to get pool
  // again take xor of everything 
    int lastsetbit = xorall & (~(xorall-1));
    for(int i=0;i<n;i++)
    {
        if(lastsetbit & a[i])
        {
            ans1 ^= a[i];
        }
        else
        {
            ans2 ^= a[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(lastsetbit & i)
        {
            ans1 ^= i;
        }
        else
        {
            ans2 ^= i;
        }
    }
  // check which one is repeating
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == ans1)
        {
            count++;
        }
    }
    if(count == 0)
    {
        return {ans2,ans1};
    }
    return {ans1,ans2};
}

// one more mathematical way to do it is to get sum of numbers and sum of squares of numebrs two eqautions two variables.
vector<int> Solution::repeatedNumber(const vector<int> &A) {
     long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;
    return {repeating,missingNumber};
    
}
