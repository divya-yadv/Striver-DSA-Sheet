// if an element is in majority despite cancelling out with different elements, its count will still be more than zero
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int k=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[k])
                count++;
            else
            {
               count--;
                if(count == 0)
                {
                    count++;
                    k = i;
                }
            }
            if(count > n/2)
                return nums[k];
        }
        return nums[k];
    }
