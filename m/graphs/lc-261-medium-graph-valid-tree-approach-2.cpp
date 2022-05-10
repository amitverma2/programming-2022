class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // create adj graph
        unordered_map<int, list<int>> adj;
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // iterative dfs, with persistent visited bitmask
        unordered_set<int> seen;
        stack<int> nodes;
        vector<bool> visited(n, false);
        visited[0] = true;
        nodes.push(0);
        seen.insert(0);
        unordered_map<int, int> coming_from;
        coming_from[0] = -1;
        
        // this DFS is right to left with respect to childrens
        while (!nodes.empty()) {
            int cur = nodes.top();
            nodes.pop();
            for (auto child: adj[cur]) {
                if (child == coming_from[cur]) {
                    continue;
                }                
                if (visited[child]) {
                    return false;
                }
                visited[child] = true;
                coming_from[child] = cur;
                nodes.push(child);
                seen.insert(child);
            }
            // since all child nodes are added in the stack, the rightmost child will be on top
        }
        return seen.size() == n;
    }
};

