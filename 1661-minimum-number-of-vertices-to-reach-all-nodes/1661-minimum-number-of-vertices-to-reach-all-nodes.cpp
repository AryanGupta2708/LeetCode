class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
         vector<bool> isIncomingEdgeExists(n, false);
        for (vector<int>& edge : edges) {
            isIncomingEdgeExists[edge[1]] = true;
        }
        
        vector<int> requiredNodes;
        for (int i = 0; i < n; i++) {
            // Store all the nodes that don't have an incoming edge.
            if (!isIncomingEdgeExists[i]) {
                requiredNodes.push_back(i);
            }
        }
        
        return requiredNodes;
    }
};