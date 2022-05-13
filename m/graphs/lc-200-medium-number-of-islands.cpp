class Solution {
public:
    bool isValid (int a, int b, int maxA, int maxB) {
        if (a < 0 || b < 0)
            return false;
        if (a >= maxA || b >= maxB)
            return false;
        return true;
    }
    
    void colorIslandStartingAt(vector<vector<int>> &grid, int a, int b, int color) {
        stack<pair<int, int>> cells;
        cells.push(make_pair(a, b));
        while (!cells.empty()) {
            auto cell = cells.top();
            cells.pop();
            grid[cell.first][cell.second] = color;
            int r[] = {-1, 1, 0, 0};
            int c[] = { 0, 0,-1, 1};
            for (int i = 0; i < 4; ++i) {
                if (isValid(cell.first + r[i], cell.second + c[i], grid.size(), grid[0].size())
                    && grid[cell.first + r[i]][cell.second + c[i]] == 1) {
                    cells.push(make_pair(cell.first + r[i], cell.second + c[i]));
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int color = 2;
        
        vector<vector<int>> intGrid(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1')
                    intGrid[i][j] = 1;
            }
        }
        
        for (int i = 0; i < intGrid.size(); ++i) {
            for (int j = 0; j < intGrid[i].size(); ++j) {
                if (intGrid[i][j] == 1) {
                    color++;
                    colorIslandStartingAt(intGrid, i, j, color);
                }
            }
        }
        return color - 2;
    }
};

