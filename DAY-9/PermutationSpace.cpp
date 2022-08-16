// generate all permutaions 
// sort them
// O(N! * N)+N!*logN! --> N is to make a deep copy and then store it to vector res
// O(N) recursion stack
void solve(string &s, vector<string>&res,int i)
    {
        if(i == s.length())
        {
            res.push_back(s);
            return;
        }
  // for every position swap it to every posible next number and make permuations
        for(int j=i;j<s.length();j++)
        {
            swap(s[i],s[j]);
            solve(s,res,i+1);
            swap(s[i],s[j]);
        }
    }
    string getPermutation(int n, int k) {
        vector<string>res;
        string s;
        for(int i=1;i<=n;i++)
        {
            s.push_back(i+'0');
        }
        solve(s,res,0);
        sort(res.begin(),res.end());
        return res[k-1];
    }

// second solution maths
