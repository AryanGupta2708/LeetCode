class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        //Easy solution
        
        int lMin = -1, lMax = -1;
        long long ct = 0;
        int n = nums.size();
        int leftB = -1;
         for (int i = 0; i < n; i++) {
              if (nums[i] >= minK && nums[i] <= maxK) {
                lMin = (nums[i] == minK) ? i : lMin;
                lMax = (nums[i] == maxK) ? i : lMax;
                ct += max(0, min(lMin, lMax) - leftB);
            } else {
               
                leftB = i;
                lMin = -1;
                lMax = -1;
            }
        }
        return ct;
    }
};