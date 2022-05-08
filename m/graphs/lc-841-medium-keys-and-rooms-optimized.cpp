class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int total_rooms = rooms.size();
        int keys_found = 0;
        vector<bool> visited(total_rooms, false);
        queue<int> pipeline;
        pipeline.push(0);
        visited[0] = true;
        keys_found++;
        
        while (keys_found < total_rooms &&
               !pipeline.empty()) {
            int cur = pipeline.front();
            pipeline.pop();
            for (auto n: rooms[cur]) {
                if (!visited[n]) {
                    keys_found++;
                    visited[n] = true;
                    pipeline.push(n);
                }
            }
        }
        if (keys_found == total_rooms) return true;
        return false;
    }
};

