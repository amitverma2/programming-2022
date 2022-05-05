class Solution {
public:
    bool cycleFound(int cur, int numCourses, unordered_map<int, vector<int>>& adj, bool *visited, bool *checked) {
        // the cur course is checked and found to be not cyclic
        if (checked[cur])
            return false;
        
        // if this course was seen before, we have a cycle, return true
        if (visited[cur])
            return true;
        
        // mark current course visited
        visited[cur] = true;
        
        bool cycle = false;
        for (auto i: adj[cur]) {
            cycle = cycleFound(i, numCourses, adj, visited, checked);
            if (cycle)
                break;
        }
        visited[cur] = false;
        checked[cur] = true; // this is actually a hack, since we can have a case of cycle found and checked is still set to true
        // the reason this works, is that as soon as we find a cycle we backtrack and don't process anything further
        // had it been a case where we have to keep on looking further (even after a cycle is found) in the courses from the caller
        // it won't work anymore
        
        return cycle;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make adj list for the table
        unordered_map<int, vector<int>> adj;
        for (auto edge: prerequisites) {
            // edge[0] needs edge[1], so edge[1] leads to edge[0] (comes before)
            adj[edge[1]].push_back(edge[0]);
        }
        
        bool * checked = new bool[numCourses]();
        bool * visited = new bool[numCourses]();
        for (int i = 0; i < numCourses; ++i) {
            if (cycleFound(i, numCourses, adj, visited, checked))
                return false;
        }
        return true;
    }
};

