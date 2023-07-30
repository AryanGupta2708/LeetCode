class Solution {
public:
    int par[100005];
    int cnt[100005];
    int f_find(int a){
        if(a == par[a]) return a;
        return par[a] = f_find(par[a]);
    }
    void f_union(int a, int b) {
        int root_a = f_find(a);
        int root_b = f_find(b);
        if(root_a == root_b) return;
        if (root_a < root_b) {
            par[root_b] = root_a;
            cnt[root_a] += cnt[root_b];
        }
        else {
            par[root_a] = root_b;
            cnt[root_b] += cnt[root_a];
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        for (int i=0; i<n; ++i) {
            par[i] = i;
            cnt[i] = 1;
        }

        for (vector<int> &cur : edges) f_union(cur[0], cur[1]);
            
        long long ans = 0, sum = 0;        
        for (int i=0; i<n; ++i) {
            if(par[i] != i) continue;
            sum += cnt[i];
            ans += (n - sum) * cnt[i];
        }

        return ans;
    }
};