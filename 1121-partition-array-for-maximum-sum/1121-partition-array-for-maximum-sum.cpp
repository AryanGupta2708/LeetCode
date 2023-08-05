class Solution {
private:
    int f(vector<int>& arr, int k, int n, int ind, vector<int> &dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len=0;
        int maxi=INT_MIN;
        int max_len=INT_MIN;
        for(int i=ind; i<min(n, ind+k); i++){
            maxi=max(maxi, arr[i]);
            len++;
            max_len=max(max_len, len*maxi+f(arr, k, n, i+1, dp));
        }
        return dp[ind]=max_len;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        
        vector<int> dp(n+1, 0);
        //return f(arr, k, n, 0, dp);
        dp[n]=0;
        for(int j=n-1; j>=0; j--){
            int len=0;
            int maxi=INT_MIN;
            int max_len=INT_MIN;
            for(int i=j; i<min(n, j+k); i++){
                maxi=max(maxi, arr[i]);
                len++;
                max_len=max(max_len, len*maxi+dp[i+1]);
            }
        dp[j]=max_len;
        }
        return dp[0];
    }
};