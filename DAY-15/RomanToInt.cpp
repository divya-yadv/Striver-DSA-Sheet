// O(N)
int romanToInt(string s) {
        int ans = 0;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            k=0;
            switch (s[i]){
                case 'I':
                      k=1;
                      break;
                case 'V':
                      k=5;
                       break;
                case 'X':
                    k=10;
                     break;
                case 'L':
                    k=50;
                     break;
                case 'C':
                    k=100;
                     break;
                case 'D':
                    k=500;
                     break;
                case 'M':
                    k=1000;
                     break;
                default:
                    break;
            }
          // check for three cases
            if(i != (s.size()-1))
            {
                if(s[i] == 'I')
                {
                    if(s[i+1] == 'V'){
                        k = 4;
                        i++;
                    }
                    else if(s[i+1] == 'X'){
                        k=9;
                        i++;
                    }
                }
                else if(s[i] == 'X')
                {
                    if(s[i+1] == 'L'){
                        k=40;
                        i++;
                    }
                    else if(s[i+1] == 'C'){
                        k=90;
                        i++;
                    }
                }
                else if(s[i] == 'C'){
                    if(s[i+1] == 'D'){
                        k=400;
                        i++;
                    }
                    else if(s[i+1] == 'M'){
                        k=900;
                        i++;
                    }
                }
            }
           
            ans += k;
        }
        return ans;
    }

// another way to write
int rotoint(char c)
    {
        int k=0;
        switch (c){
                case 'I':
                      k=1;
                      break;
                case 'V':
                      k=5;
                       break;
                case 'X':
                    k=10;
                     break;
                case 'L':
                    k=50;
                     break;
                case 'C':
                    k=100;
                     break;
                case 'D':
                    k=500;
                     break;
                case 'M':
                    k=1000;
                     break;
                default:
                    break;
            }
        return k;
    }
    int romanToInt(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            int k=rotoint(s[i]);
            if((i!=(s.size()-1)) && (k < rotoint(s[i+1])))
            {
                ans -= k;
            }
           else
           {
               ans += k;
           }
        }
        return ans;
    }
