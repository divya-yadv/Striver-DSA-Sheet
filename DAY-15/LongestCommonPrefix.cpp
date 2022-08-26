// O(prefix string)*O(N)
string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int k=0;
  // will check for every common word in string
        while(true) {
            char c;
            if(k < strs[0].size())
                 c = strs[0][k];
            else
                return s;
            int i;
            for(i=1;i<strs.size();i++)
            {
                if((k<strs[i].size()) && (strs[i][k] == c))
                {
                    continue;
                }
                else
                {
                    return s;
                }
                
            }
            s += c;
            k++;
        }
        return s;
        
    }

 string longestCommonPrefix(vector<string>& strs) {
        // there is one more way to do this we can find the lexigraphical order of first and last string these are the strings that will show maximum difference 
        string start = strs[0];
        string end = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            if(strs[i]< start)
            {
                start = strs[i];
            }
            if(strs[i]> end)
            {
                end = strs[i];
               
            }
        }
        string ans="";
        for(int i=0;i<min(start.size(),end.size());i++)
        {
            if(start[i] == end[i])
               ans += start[i];
            else
                return ans;
        }
        return ans;
    }
