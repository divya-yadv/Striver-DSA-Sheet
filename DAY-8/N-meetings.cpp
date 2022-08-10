O(N*logN)->sort, O(N)    

static bool mycomp(pair<int,int>p1, pair<int,int>p2)
    {
        return p1.second<p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
      // put both in a vector
       vector<pair<int,int>> v;
       for(int i=0;i<n;i++)
       {
           v.push_back({start[i],end[i]});
       }
      // sort according to ending time
       sort(v.begin(),v.end(),mycomp);
       int ans = 1;
       int last = v[0].second;
       for(int i=1;i<n;i++)
       {
         // if last meeting ended start next one
           if(v[i].first > last)
           {
               ans++;
               last = v[i].second;
           }
       }
       return ans;
    }
