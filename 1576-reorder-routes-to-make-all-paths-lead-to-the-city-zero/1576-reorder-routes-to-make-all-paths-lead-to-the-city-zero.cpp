vector<vector<pair<int,bool>>> adj(50000+1);
class Solution {
public:
    int DFS(int root, int parent){
        int ans = 0;
        for (int i = 0; i < adj[root].size(); i++){
            if (adj[root][i].first!=parent){
                if (adj[root][i].second==true)
                ans += 1 + DFS(adj[root][i].first, root);
                else
                ans += DFS(adj[root][i].first, root);
            }
        }
        //cout<<ans<<" "<<root<<"\n";
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for (int i = 0; i < n; i++){
            adj[i].clear();
        }
        for (int i = 0;i < connections.size(); i++){
            adj[connections[i][0]].push_back(make_pair(connections[i][1], true));
            adj[connections[i][1]].push_back(make_pair(connections[i][0], false));
        }
        int ans = DFS(0, -1);
        return ans;
    }
};