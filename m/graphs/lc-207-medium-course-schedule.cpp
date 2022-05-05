class Solution {
public:
    void visit(int c, bool visited[2001]) {
        //cout << "Visit " << c << " was currently marked " << (visited[c]?"visited":" not visited") << endl;
        return;
    }
    
    // returns true if a cycle is found
    bool dfs(int c, int N, int graph[2001][2001],bool visited[2001], bool confirmedGoodList[2001]) {
        // Take the shortcut
        if (confirmedGoodList[c])
            return false;
        
        if (visited[c])
            return true;
        
        visited[c] = true;
        
        bool hasCycle = false;
        for (int i = 0; i < N; ++i) {
            if (graph[c][i]) {
                hasCycle = dfs(i, N, graph, visited, confirmedGoodList);
                if (hasCycle)
                    break;
            }
        }
        
        visited[c] = false;
        confirmedGoodList[c] = true;
        
        return hasCycle;
    }
    
    bool foundCycle (int c, int N, int graph[2001][2001], bool confirmedGoodList[2001]) {
        //cout << "Finding cycle for " << c << endl;
        bool visited[2001] = { false };
        if (!dfs(c, N, graph, visited, confirmedGoodList)) {
            confirmedGoodList[c] = true; // confirmed that this node does not come in a path that has cycles
            return false;
        }
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int graph[2001][2001] = {0};
        for (auto edge : prerequisites) {
            graph[edge[0]][edge[1]] = 1;
            if (graph[edge[1]][edge[0]])
                return false;   // direct edge loop
        }
        // no direct edge loop found do the hard BFS walk per node
        bool confirmedGood[2001] = { false };
        for (int c = 0; c < numCourses; ++c) {
            if (foundCycle(c, numCourses, graph, confirmedGood))
                return false;
        }
        return true;
    }
};

