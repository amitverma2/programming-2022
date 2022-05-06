class Solution {
    unsigned long min_time = UINT_MAX;
    unsigned long num_ways = 0;
    bool visited[200] = { false };
    unordered_map<int, vector<pair<int, int>>> adj;
public:
    void dfs (int cur, int target, unsigned long time) {
        //cout << "Visiting " << cur << endl;
        if (cur == target) {
            unsigned long this_time = time;
            if (this_time == min_time) {
                num_ways = (num_ways + 1) % (1000000000 + 7);
                //cout << "Min time is " << min_time << " with num ways " << num_ways << endl;
            } else if (this_time < min_time) {
                num_ways = 1;
                min_time = this_time;
                //cout << "Reset num ways to 1, and min time to " << min_time << endl;
            }
            return;
        }
        // pruning - short cut
        if (time > min_time) {
            //cout << "Cur time " << time << " is more than best time " << min_time << " hence exiting.\n";
            return;
        }
        unsigned long to_cache = UINT_MAX;
        //cout << "Iterating over the neighbours of it..." << endl;
        for (auto c: adj[cur]) {
            int n = c.first;
            unsigned long n_time = time + c.second;
            if (!visited[n]) {
                visited[n] = true;
                dfs(n, target, n_time);
                visited[n] = false;
            }
        }
        return;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        for (auto i: roads) {
            adj[i[0]].push_back(make_pair(i[1], i[2]));
            adj[i[1]].push_back(make_pair(i[0], i[2]));
        }
        visited[0] = true;
        dfs(0, n - 1, 0);
        return num_ways % (1000000000 + 7);
    }
};

