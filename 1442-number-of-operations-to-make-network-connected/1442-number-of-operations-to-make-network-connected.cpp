class Solution {
public:
    void dfs(vector<int> adj[],int u,vector<bool> &vis){
        vis[u]=true;
        for(auto v:adj[u]){
            if(vis[v]==false){
                dfs(adj,v,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        int m=c.size();
        cout<<n<<" "<<m<<endl;
        if(m<(n-1)){
            return -1;
        }
        int count=0;
        vector<bool> vis(n,false);
        vector<int> adj[n];
        for(auto it:c){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(adj,i,vis);
                count++;
            }
        }
        return count-1;
    }
};