class Solution {
public:
    vector<int>dx={1,0};
    vector<int>dy={0,1};
    
    int f(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
    {
        if (i+1==grid.size() && j+1==grid[0].size())
        {
            return grid[i][j];
        }
        if (i>=grid.size() || j>=grid[0].size() || i<0 || j<0)
        {
            return INT_MAX;
        }
        if (dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=grid[i][j]+min(f(grid,i+dx[0],j+dy[0],dp),f(grid,i+dx[1],j+dy[1],dp));
        return dp[i][j]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(grid,0,0,dp);    
    }
};