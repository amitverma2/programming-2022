class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> in_adj;
        unordered_map<int, list<int>> out_adj;
        for (auto p: prerequisites) {
            in_adj[p[0]].push_back(p[1]);
            out_adj[p[1]].push_back(p[0]);
        }
        queue<int> course_order;
        queue<int> no_pred;
        
        for (int i = 0; i < numCourses; ++i) {
            if (in_adj.find(i) == in_adj.end())
                no_pred.push(i);
        }
        
        while (!no_pred.empty()) {
            int c = no_pred.front();
            no_pred.pop();
            course_order.push(c);          
           
            // find edges from c to other node n and remove those isn the in_adj
            for (auto i: out_adj[c]) {
                in_adj[i].remove(c);
            }
            out_adj.erase(c);
            
            // find the courses with no in adj and add to no_pred list
            vector<int> tbd;
            for (auto v: in_adj) {
                if (v.second.size() == 0) {
                    no_pred.push(v.first);
                    tbd.push_back(v.first);
                }
            }
            for (int i: tbd) {
                in_adj.erase(i);
            }
        }
        
        if (in_adj.size() > 0)
            return false;
        else
            return true;
    }
};

