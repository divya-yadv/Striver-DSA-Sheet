// O(N)
// 
int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int v1 = 0;
        int v2 = 0;
        int i=0;
        int j=0;
        while((i < n )||( j<m ))
        {
          // we will compare for every number that is between the dotes if thats same we have to got further
            while((i<n) && (version1[i] != '.'))
            {
                // v1 is anyways 0 until we hit a digit
                v1 = v1*10+(version1[i]-'0');
                i++;
            }
            while((j<m)&& (version2[j]!='.'))
            {
                v2 = v2*10+(version2[j]-'0');
                j++;
            }
            if(v1>v2)
                return 1;
            else if(v1<v2)
                return -1;
            i++;
            j++;
            v1=0;
            v2=0;
        }
        return 0;
    }
