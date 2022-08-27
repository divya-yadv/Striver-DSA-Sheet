// using RabinKarp algortihm can use KMP as well
int strStr(string txt, string pat) {
      
        int n = txt.length();
        int m = pat.length();
          if(m == 0)
            return 0;
        if(n == 0 || (n<m))
            return -1;
        int d = 31;
        int q = 15486703;
        long  hashpat = 0;
        long  hashtxt = 0;
        long  h=1;
        // The value of h would be "pow(d, M-1)%q" 
      // calculate hash for first n2 length in txt and pattern
        for(int i=0;i<m;i++)
        {
            if(i != m-1)
                h = (h*d)%q;
            hashpat = (d*hashpat + pat[i])%q;
            hashtxt = (d*hashtxt + txt[i])%q;
        }
        for(int i=0;i<=n-m;i++)
        {
          // check if pattern matched
            if(hashpat == hashtxt)
            {
              // now compare all
                int j;
                for(j=0;j<m;j++)
                {
                    if(txt[i+j] != pat[j])
                        break;
                }
              // if all equal then its a match
                if(j == m)
                {
                    return i;
                }
            }
          // compute hash for next one
            if(i< (n-m))
            {
                hashtxt = (d*(hashtxt-(txt[i]*h))+txt[i+m])%q;
              // if hash becomes negative make it pos
                if(hashtxt < 0)
                    hashtxt += q;
            }
        }
        return -1;
    }
