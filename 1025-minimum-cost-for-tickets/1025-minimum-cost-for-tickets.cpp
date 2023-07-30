class Solution {
public:int solve(vector<int>&nums,vector<int>&c,int i,vector<int>&dp){
        if(i>=nums.size())
                return 0;
        
        if(dp[i]!=-1)
                return dp[i];
                
        int one =c[0]+solve(nums,c,i+1,dp);
        
        int j=0;
        int n = nums.size();
        for( j=i; j<n&&nums[j]<nums[i]+7; j++);
        int two=c[1]+solve(nums,c,j,dp);
        
        int k=0;
        for( k=i; k<n&&nums[k]<nums[i]+30; k++);
        int three=c[2]+solve(nums,c,k,dp);
        
        
        return dp[i]=min(one,min(two,three));
                
          
}
    int mincostTickets(vector<int>& d, vector<int>& c) {
            vector<int>dp(d.size()+1,-1);
            return solve(d,c,0,dp);
        
    }
};