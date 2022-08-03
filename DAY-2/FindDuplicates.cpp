int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
          // that means if we have added same element before, value is greater than n == nums[i]+n;
            if(nums[nums[i]%n] > n)
                return nums[i]%n;
            nums[nums[i]%n] += n;
        }
        return -1;
    }
// we can also use linked list cycle method to detect the cycle.
int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
// both O(N), O(1) SOLUTIONS 
