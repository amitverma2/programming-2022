class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> out_courses(numCourses);
        
        for (auto edge: prerequisites) {
            in_degree[edge[0]]++;
            out_courses[edge[1]].push_back(edge[0]);
        }
              
        queue<int> S;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                S.push(i);
            }
        }
        
        while (!S.empty()) {
            int course = S.front();
            S.pop();
            numCourses--;            
            for (auto dependent: out_courses[course]) {
                if (--in_degree[dependent] == 0) {
                    S.push(dependent);
                }
            }
        }

        return !numCourses;
    }
};

