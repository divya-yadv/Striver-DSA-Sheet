// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1
// we are adding space at n possible spots O(2^N * n) n->find in dict of n, N are number of spots either add a space of don't
// N -> recursion stack
bool isPresent(vector<string>&dict,string s)
    {
        if(find(dict.begin(),dict.end(),s) != dict.end())
        {
            return true;
        }
        return false;
    }
    void solve(vector<string>dict, string s,int i, string curr,vector<string>&res)
    {
        if(i == s.length())
        {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
      // start adding from this index for every possible substring
        string str="";
        for(int k=i;k<s.length();k++)
        {
            str += s[k];
          // check if present 
            if(isPresent(dict,str))
            {
              // solve further 
                solve(dict,s,k+1,curr+str+" ",res);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> res;
        if(n == 0 || s.length() == 0)
        {
            return res;
        }
        string curr = "";
        solve(dict,s,0,curr,res);
    }
