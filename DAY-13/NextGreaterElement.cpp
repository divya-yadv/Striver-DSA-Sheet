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
