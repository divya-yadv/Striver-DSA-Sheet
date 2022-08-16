// recursive solution
// O(2^n*k*(n/2)) -> 2^n for all combinations , O(n/2) to check if its palindrome , O(K) is to insert it into a vector
// O(k*x)
// 

bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(string s,int i,vector<string>&v,vector<vector<string>>&res)
    {
      // if travsersed whole string then push the result 
        if(i == s.length())
        {
            res.push_back(v);
            return;
        }
      // start making palindrome for particular point 
        for(int j=i;j<s.length();j++)
        {
          // check of every i,j
            if(isPalindrome(s,i,j))
            {
                v.push_back(s.substr(i,j-i+1));
                solve(s,j+1,v,res);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        solve(s,0,v,res);
        return res;
    }

// can have a DP solutuin as well just by storing if already checked for particular substring
