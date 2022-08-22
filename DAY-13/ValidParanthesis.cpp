char open(char s)
    {
        if(s == '}')
        {
            return '{';
        }
        else if(s == ')')
        {
            return '(';
        }
         else
        {
            return '[';
        }
        return 'p';
    }
    bool isValid(string s) {
        stack<int>st;
        bool flag = false;
        for(int i=0;i<s.size();i++)
        {
            if((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            {
                st.push(s[i]);
            }
            else
            {
              // if didn't find previous pushed element as opening bracket
                if((st.empty()) || (!st.empty() && (st.top() != open(s[i]))))
                {
                   return false;
                }
                st.pop();
            }
        }
      // if open brackets are still there
        return st.size() == 0?true:false;
    }
