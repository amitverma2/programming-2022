class Solution {
public:
    void dfs (int cur, int n, vector<vector<int>> &graph, vector<vector<int>> &paths, vector<int> &trace) {
        if (cur == n) {
            paths.push_back(trace);
            return;
        }
        for (auto i: graph[cur]) {
            trace.push_back(i);
            dfs(i, n, graph, paths, trace);
            trace.pop_back();
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> trace;
        int n = graph.size() - 1;
        trace.push_back(0);
        dfs(0, n, graph, paths, trace);
        return paths;
    }
};

