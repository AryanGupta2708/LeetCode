#define ll long long
#define MOD 1000000007
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        ll n = pizza.size();
        ll m = pizza[0].size();
        vector <vector <ll>> pre(1+n, vector <ll>(1+m, 0));
        for (ll i=n-1; i>=0; i--)
            for (ll j=m-1; j>=0; j--)
                pre[i][j] = pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1] + (pizza[i][j]=='A');
    
        vector <vector <vector <ll>>> dp(1+n, vector <vector <ll>>(1+m, vector <ll>(k, -1)));
        return solve (0, 0, k-1, dp, pre);
    }
    
    ll solve (int r, int c, int k, vector <vector <vector <ll>>>& dp, vector <vector <ll>>& pre)
    {
        ll n = dp.size();
        ll m = dp[0].size();
        
        if (dp[r][c][k]!=-1)
            return dp[r][c][k];
        
        dp[r][c][k] = 0;
        
        if (!k)
            return dp[r][c][k] = (pre[r][c]!=0);
        
        for (ll i=r+1; i<n; i++)
            if (pre[r][c]>pre[i][c])
                dp[r][c][k] = modSum(dp[r][c][k], solve(i, c, k-1, dp, pre));
        for (ll i=c+1; i<m; i++)
            if (pre[r][c]>pre[r][i])
                dp[r][c][k] = modSum(dp[r][c][k], solve(r, i, k-1, dp, pre));
     
        return dp[r][c][k];
    }
    
    ll modSum (ll a, ll b) {return ((a%MOD)+(b%MOD))%MOD;}
};