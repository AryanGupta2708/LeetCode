class Solution {
public:
    vector<int> group;
    int look(int a){
        return (a==group[a])? a:look(group[a]);
    }
    int minScore(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        group.resize(n+1);
        vector<int> dis(n+1, INT_MAX);
        int i, l1, l2;
        for(i=1; i<n+1; i++)    group[i]=i;
        for(i=0; i<roads.size(); i++){
            l1=look(roads[i][0]);
            l2=look(roads[i][1]);
            if(l1>l2)   swap(l1, l2);
            group[l2]=l1;
            group[l1]=l1;
            dis[l1]=(dis[l1]<dis[l2]&&dis[l1]<roads[i][2])?dis[l1]:(dis[l2]<roads[i][2])?dis[l2]:roads[i][2];
        }
        return dis[look(n)];
    }
};