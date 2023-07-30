class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if (n==1) return 0;
        unordered_map<int,int> mp;
        vector<vector<int>> edges;
        int ix = 0;
        for(int i = 0; i<n; i++)
        {   // Change array value to sequencial get rid of map 
            // in graph later (edge index is the value in arr[i])
            auto tr = mp.find(arr[i]);
            if (tr == mp.end()) 
            {   
                mp[arr[i]] = edges.size();
                arr[i]     = edges.size();
                edges.push_back({i});   // add index to adjes
            }
            else
            {
              arr[i] =  tr->second;
              edges[tr->second].push_back(i);
            }
        }
        int m = edges.size();
        vector<int> visited(n,0);
        vector<int> ev(m,0);  // Make sure to process each vector once
        queue<int> q1;
        queue<int> q2;
        queue<int> &q = q1;
        queue<int> &q_next = q2;
        q.push(0);
        visited[0] = 1;
        int step = 0;
        while(!q.empty())
        {
            step++;
            while(!q.empty())
            {
                int i = q.front();
                q.pop();
                if (i>0  && !visited[i-1])
                {
                    visited[i-1] = true;
                    q_next.push(i-1);
                }
                if (!visited[i+1])
                {
                    if (i+1 == n-1) return step;
                    visited[i+1] = true;
                    q_next.push(i+1);
                }
                if (ev[arr[i]]) continue;
                ev[arr[i]] = 1;
                for(int x : edges[arr[i]])
                {
                    if (visited[x]) continue;
                    if (x == n-1) return step;
                    visited[x] = true;
                    q_next.push(x);
                }
           }
           swap(q,q_next);
        }
        return step;  // should never happend
    }

};