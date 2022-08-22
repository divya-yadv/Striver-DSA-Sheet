// O(N^2)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
              // found ith element
                if((nums1[i] == nums2[j]))
                {
                  // now search for greater element
                    int k=j+1;
                    bool flag = false;
                    while(k<nums2.size())
                    {
                        if(nums2[k] > nums2[j])
                        {
                            ans.push_back(nums2[k]);
                            flag=true;
                            break;
                        }
                    }
                  // not found return -1
                    if(flag == false)
                    {
                        ans.push_back(-1);
                    }
                    break;
                }
            }
        }
        return ans;
    }
// O(N+M)
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        unordered_map<int,int>mp;
        stack<int>st;
         // pre-compute next greater element and store it in map
        for(auto n:nums2)
        {
            while(!st.empty() && (st.top()<n))
            {
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        for (int i=0; i<nums1.size(); i++) {
        auto itr = mp.find(nums1[i]);
        if (itr != mp.end()) {
            ans[i] = itr->second;
        }
    }
        return ans;
    }
