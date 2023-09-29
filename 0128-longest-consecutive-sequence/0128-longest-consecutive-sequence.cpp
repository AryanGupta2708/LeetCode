class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
        return nums.size();

        sort(nums.begin(),nums.end());
        int count = 1,maxi = 0;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
            continue;
            if(nums[i] + 1 == nums[i+1]){
                count++;
            }
            else{
                count = 1;
            }

            maxi = max(count,maxi);
        }
        maxi = max(count,maxi);

        return maxi;
        
    }
};