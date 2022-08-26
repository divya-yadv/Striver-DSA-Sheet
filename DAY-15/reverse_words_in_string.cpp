// O(N),O(N)
string reverseWords(string s) {
        stack<string> st;
        string curr="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
            {
                curr += s[i];
            }
            else
            {
                if(curr != "")
                    st.push(curr);
                curr="";
            }
        }
        if(curr != "")
             st.push(curr);
        string res="";
        while(!st.empty())
        {
            res += st.top()+' ';
            st.pop();
        }
        res.pop_back();
        return res;
    }
