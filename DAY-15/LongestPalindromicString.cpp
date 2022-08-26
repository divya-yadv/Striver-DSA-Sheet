//O(N*(N(N-1)/2->for possible substrings) -> O(N^3)
// check for every substring
bool isPalindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int res = 0;
        string p="";
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(isPalindrome(s,i,j)){
                    if(j-i+1 > res)
                    {
                        res = max(res,j-i+1);
                        p = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return p;
    }

// DP solution O(N^3) ,  O(N^2)
string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1)
            return s;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        string ans="";
        ans += s[0];
    // single is always palindrome
        for(int i=0;i<n;i++)
        {
            dp[i][i] = true;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i] == s[j])
                {
                    //bb i=0,j=1
                    // or
                    // babab , i=b,j=b, i+1->j-1 == aba
                    if(((j-i) == 1 ) || (dp[i+1][j-1]))
                    {
                        dp[i][j] = true;
                        if(ans.size() < (j-i+1))
                        {
                            ans = s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return ans;
    }
