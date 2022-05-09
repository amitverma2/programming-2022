class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        stack<int> node_stack;
        node_stack.push(0);
        unordered_set<int> seen;
        seen.insert(0);
        while (!node_stack.empty()) {
            int cur_node = node_stack.top();
            node_stack.pop();
            for (auto child : adj[cur_node]) {
                if (seen.find(child) == seen.end()) {                    
                    seen.insert(child);
                    node_stack.push(child);
                    adj[child].remove(cur_node); // take backward edge out.
                } else {
                    return false;
                }
            }
        }
        return seen.size() == n;
    }
};

