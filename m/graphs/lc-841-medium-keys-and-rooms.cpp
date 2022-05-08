class Solution {
    int total_rooms;
    unordered_set<int> found_keys;
    vector<bool> visited;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        total_rooms = rooms.size();
        visited.resize(total_rooms);
        found_keys.insert(0);
        
        queue<int> pipeline;
        pipeline.push(0);
        while (found_keys.size() < total_rooms &&
               !pipeline.empty()) {
            int room = pipeline.front();
            pipeline.pop();
            visited[room] = true;
            for (auto n: rooms[room]) {
                found_keys.insert(n);
                if (!visited[n]) {
                    visited[n] = true;
                    pipeline.push(n);
                }
            }
        }

        if (found_keys.size() == total_rooms) return true;
        return false;
    }
};

