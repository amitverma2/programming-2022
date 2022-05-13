class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n < 2) {
            vector<int> results;
            for (int i = 0 ; i < n; ++i) {
                results.push_back(i);
            }
            return results;
        }
        
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        int remaining = n;
        while (remaining > 2) {
            remaining -= leaves.size();
            vector<int> next_leaves;
            for (auto x: leaves) {
                int leave_neighbour = adj[x].front();
                adj[leave_neighbour].remove(x);
                if (adj[leave_neighbour].size() == 1) {
                    next_leaves.push_back(leave_neighbour);
                }
            }
            leaves = next_leaves;
        }
        return leaves;
    }
};

