class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums2;                
        int x;
        for(int i=0;i<nums.size();i++){
            x = target - nums[i];
          auto it = find(nums.begin()+i+1,nums.end(),x);
            if(it!=nums.end()){
            nums2.push_back(i);
            nums2.push_back(it-nums.begin());    
            break;
            }
        }
        
        return nums2;
    }
};