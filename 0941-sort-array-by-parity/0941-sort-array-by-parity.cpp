class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                temp = nums[i];
                nums.erase(nums.begin() + i);
                nums.insert(nums.begin(),temp);
            }


        }

        return nums;
        
    }
};