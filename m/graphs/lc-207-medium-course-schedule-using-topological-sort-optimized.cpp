class Solution {
    struct Course {
        int in_degree;
        list<int> out_courses;
        Course(): in_degree(0) { }
    };
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, struct Course> course_graph;
        
        for (auto edge: prerequisites) {
            course_graph[edge[1]].out_courses.push_back(edge[0]);
            course_graph[edge[0]].in_degree++;
        }
        
        int edges = prerequisites.size();
        
        queue<int> S;
        for (auto courses: course_graph) {
            if (courses.second.in_degree == 0) {
                S.push(courses.first);
            }
        }
        
        while (!S.empty()) {
            int course = S.front();
            S.pop();
            
            for (auto dependents: course_graph[course].out_courses) {
                if (--course_graph[dependents].in_degree == 0) {
                    S.push(dependents);
                }
                --edges;
            }
        }

        if (edges > 0)
            return false;
        
        return true;
    }
};

