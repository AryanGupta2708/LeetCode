class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]])
            mp[nums[i]] = 0;
            mp[nums[i]]++;
        }
        int n = nums.size();
        nums.clear();
        
        for(auto i : mp){
            if(i.second > float(n/3)){
                nums.push_back(i.first);
            }
        }

        return nums;
        
    }
};