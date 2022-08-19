int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            // if low is less than mid 
            if (nums[low] <= nums[mid]){
                // if target is between low to mid,
                if(target >= nums[low] and target <= nums[mid]){
                    high = mid;
                } else {
                    // if target is beyond mid
                    low = mid + 1;
                }
                // if low is greater than mid,
            } else{
                // if target is between mid to high
                if(target >= nums[mid] and target <= nums[high]){
                    low = mid + 1;
                } else {
                    // if target is greater than high and mid both
                    high = mid;
                }
            }
        }
        
        return -1;
    }
