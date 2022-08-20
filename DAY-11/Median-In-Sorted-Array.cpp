// O(log(min(m,n))
// O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size()<nums1.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int pos = (n+m+1)/2;
        int low = 0;
        int high = m;
        while(low<=high)
        {
            int cut1 = (high+low)/2;
            int cut2 = pos-cut1;
            int l1 = (cut1 == 0)?INT_MIN:nums1[cut1-1] ;
            int l2 = (cut2 == 0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)?INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)?INT_MAX:nums2[cut2];
            if((l1 <= r2) && (l2 <= r1))
            {
                if((m+n)%2 == 0)
                {
                    double ans = (max(l1,l2)+min(r1,r2))/2.0;
                    return ans;
                }
                else
                {
                    return double(max(l1,l2));
                }
            }
            else if(l1 > r2)
            {
                high = cut1-1;
            }
            else
            {
                low = cut1+1;
            }
        }
        return 0;
    }
