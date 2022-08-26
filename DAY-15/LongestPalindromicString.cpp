//O(N^4)
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
