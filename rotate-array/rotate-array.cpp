class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
       while(k>nums.size()){
           k=k-nums.size();
       }
        if(k==nums.size()){
            return;
        }
        vector<int> num;
        num.assign(nums.begin()+nums.size()-k,nums.end());
              
        for(int i=0;i<nums.size()-k;i++){
            num.push_back(nums[i]);
        }
    nums.swap(num);
    }
     
};