// so many edge cases better to check for 0<i<9 only
int myAtoi(string s) {
        long long ans=0;
        int sign=1;
        int i=0;
        while(i<s.size())
        {
           if((s[i] == ' '))
               i++;
            else 
                break;
        }
        if(s[i] == '-'){
            sign=(-1);
            i++;
        }
        else if (s[i] == '+')
            i++;
        while(i<s.size())
        {
            if(s[i] == '0')
                i++;
            else
                break;
        }
        bool ovf = false;
        for(int k=i;k<s.size();k++)
        {
            if(s[k] >= '0' && s[k] <= '9')
            {
                 if((ans*10 +s[k]-'0') > INT_MAX)
                {
                    ovf = true;
                    break;
                 }
           
                 ans = ans*10+(s[k]-'0');
            }
           
             else
                 break;
            
        }
        if(ovf)
        {
            if(sign == -1)
                return INT_MIN;
            else
                return INT_MAX;
        }
        return (int)ans*sign;
    }
