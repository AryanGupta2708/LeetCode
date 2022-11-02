class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(auto i=0;i<nums.size()-1;i=i+2){
            if(nums[i]!=nums[i+1]){
                int x = nums[i];
                return x;
            }            
        }
     return nums.back();  
    }
};