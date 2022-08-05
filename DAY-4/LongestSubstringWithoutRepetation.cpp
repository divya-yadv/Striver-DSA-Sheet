int lengthOfLongestSubstring(string s) {
        int start = -1;
        int maxlength = 0;
        vector<int>dict(256,-1);
        for(int i=0;i<s.length();i++)
        {
          // if repeating start again and include that point index+1;
            if(dict[s[i]] > start)
            {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxlength = max(maxlength,i-start);
        }
        return maxlength;
    }
