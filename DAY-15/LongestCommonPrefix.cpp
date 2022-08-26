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
