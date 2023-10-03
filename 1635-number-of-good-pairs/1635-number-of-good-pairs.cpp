class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = 0;

        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int count = 0;
            while(j<nums.size() && nums[j]==nums[i]){
                count++;j++;
            }
            s+=count;

        }
        return s;
        
    }
};