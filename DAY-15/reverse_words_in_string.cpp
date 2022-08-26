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

// O(N),O(1)

string reverseWords(string s) {
        string curr="";
         string res="";
        // traverse from last and store a word in reverse order
        // add it to res
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] != ' ')
            {
                curr = s[i]+curr;
            }
            else
            {
                if(curr != "")
                    res += curr + ' ';
                curr="";
            }
        }
        if(curr != "")
             res += curr + ' ';
        res.pop_back();
        return res;
    }
