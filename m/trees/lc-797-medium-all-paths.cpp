class Solution {
public:
    void dfs (int cur, int n, vector<vector<int>> &graph, vector<vector<int>> &paths, vector<int> &trace) {
        trace.push_back(cur);
        if (cur == n) {
            paths.push_back(trace);
            trace.pop_back();
            return;
        }
        for (auto i: graph[cur]) {
            dfs(i, n, graph, paths, trace);
        }
        trace.pop_back();
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> trace;
        int n = graph.size() - 1;
        dfs(0, n, graph, paths, trace);
        return paths;
    }
};

