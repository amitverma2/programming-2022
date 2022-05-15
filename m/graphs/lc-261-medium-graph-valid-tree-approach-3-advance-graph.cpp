class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // a graph can only be a fully connected tree with no cycles if
        // the number of edges are exactly n - 1
        // this needs to be studied further
        
        if (edges.size() != n - 1) return false;
        
        // create adj graph
        unordered_map<int, list<int>> adj;
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // check if all nodes are visited by a dfs starting at 0
        unordered_set<int> seen;
        stack<int> node_stack;
        node_stack.push(0);
        seen.insert(0);
        while (!node_stack.empty()) {
            int cur = node_stack.top();
            node_stack.pop();
            for (auto n: adj[cur]) {
                if (seen.find(n) != seen.end()) {
                    continue;
                }
                seen.insert(n);
                node_stack.push(n);
            }
        }
        return seen.size() == n;
    }
};

