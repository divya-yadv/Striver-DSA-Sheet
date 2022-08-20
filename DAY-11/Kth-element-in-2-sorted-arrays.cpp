// approach first two pointer merge two arrays -> O(N+M),O(1) will work for median of two arrays as well
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int count=0;
        int l1 = 0;
        int l2 = 0;
        while((l1<n) && (l2<m))
        {
            if(arr1[l1] <= arr2[l2])
            {
                count++;
                if(count == k)
                {
                    return arr1[l1];
                }
                l1++;
            }
            else
            {
                count++;
                 if(count == k)
                {
                    return arr2[l2];
                }
                l2++;
            }
        }
        while(l1<n)
        {
            count++;
                if(count == k)
                {
                    return arr1[l1];
                }
                l1++;
        }
        while(l2<m)
        {
             count++;
                if(count == k)
                {
                    return arr2[l2];
                }
                l2++;
        }
        return 0;
    }

// approach second same as median of two arrays -> O(min(m,n)),O(1)

int kthElement(int nums1[], int nums2[], int m, int n, int k)
    {
        if(n<m)
        {
            return kthElement(nums2,nums1,n,m,k);
        }
        // low and high will be according to how many elements we have to pick from first array keeping k value in minf
        // min elements should be when we picked all elements from second array and still need to take few from first so can't take zero
        int low = max(0,k-n);
        // we can't choose more than k
        int high = min(m,k);
        while(low<=high)
        {
            int cut1 = (high+low)/2;
            int cut2 = k-cut1;
            int l1 = (cut1 == 0)?INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)?INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)?INT_MAX:nums2[cut2];
            if((l1 <= r2) && (l2 <= r1))
            {
                return double(max(l1,l2));
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
