string countAndSay(int n) {
        if(n == 1)
        {
            return "1";
        }
  //get temp
        string temp = countAndSay(n-1);
  // count characters and add count+char;
        int count=1;
        char c=temp[0];
        string ans = "";
        for(int i=1;i<temp.length();i++)
        {
            if(temp[i] != c)
            {
                ans += to_string(count)+c;
                count = 1;
                c = temp[i];
            }
            else
                count++;
        }
        ans += to_string(count)+c;
        return ans;
    }
