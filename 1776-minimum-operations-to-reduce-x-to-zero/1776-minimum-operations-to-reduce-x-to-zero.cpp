class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size(),sum = 0,val = 0,len = 0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum] = i;
        }
            mp[0] = 0;

        if(x>sum)
        return -1;
        sum=sum-x;
        
        for(int i=0;i<nums.size();i++){

            val+=nums[i];
            if(mp.count(val - sum)){
                if(val - sum == 0)
                len = max(len,i-mp[val-sum]+1);
                else
                len = max(len,i-mp[val-sum]);

            }
        }

        return len==0?(sum==0?n:-1):n-len;


    }
};