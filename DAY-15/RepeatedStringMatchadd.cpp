bool RabinKarp(string txt,string pat)
    {
        int n1 = txt.length();
        int n2 = pat.length();
        int d = 256;
        int q = INT_MAX;
        long long hashpat = 0;
        long long hashtxt = 0;
        long long h=0;
        // The value of h would be "pow(d, M-1)%q" 
        for (int i = 1; i <= n2 - 1; i++) {
             h = (h * d) % q; 
        }
        for(int i=0;i<n2;i++)
        {
            hashpat = (d*hashpat + pat[i])%q;
            hashtxt = (d*hashtxt + txt[i])%q;
        }
        for(int i=0;i<=n1-n2;i++)
        {
            if(hashpat == hashtxt)
            {
                int j;
                for(j=0;j<n2;j++)
                {
                    if(txt[i+j] != pat[j])
                        break;
                }
                if(j == n2)
                    return true;
            }
            if(i< (n1-n2))
            {
                hashtxt = (d*(hashtxt-(txt[i]*h))+txt[i+n2])%q;
                if(hashtxt < 0)
                    hashtxt += q;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a == b)
            return 1;
        string txt = a;
        int count=1;
        int n2 = b.size();
      // first make the txt size greater than pattern to make it possible
        while(txt.size() < n2)
        {
            txt += a;
            count++;
        }
      // if same return
        if(txt == b)
            return count;
      // else search for pattern
        if(RabinKarp(txt,b))
            return count;
      // add one more time and search
        if(RabinKarp(txt+a,b))
            return count+1;
        return -1;
    }
