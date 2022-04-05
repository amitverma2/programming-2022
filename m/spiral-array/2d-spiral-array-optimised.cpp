#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> SpiralFill(int n) {
  // Create a n * n array
  vector<vector<int>> result(n);
  for (int r = 0; r < n; ++r) {
    result[r].resize(n);
  }
  // Where am I
  int x = 0;
  int y = 0;
  // Who am I
  int cur = 1;
  // Which direction I am heading
  int dir = 0; // 0 - right, 1 - down, 2 - left, 3 - up
  // Easy way to update the next pos, indexed on direction
  const int dr[] = { 0, 1, 0, -1 };
  const int dc[] = { 1, 0, -1, 0 };
  // Am I done filling all the cells
  while (cur <= n*n) {
    // Fill the current cell
    result[x][y] = cur;
    // Update next value to fill
    ++cur;
    // Move to next position based on current direction
    x += dr[dir];
    y += dc[dir];
    // Check if I've gone beyond the array or hit a filled cell
    if (x < 0 || y < 0 || x >= n || y >= n || result[x][y]) {
      // We've gone beyond array bounds or hit a filled cell, change directions
      // Undo current position update
      x -= dr[dir];
      y -= dc[dir];
      // Change the direction
      dir = (dir+1) % 4;
      // Move to next position based on new direction
      x += dr[dir];
      y += dc[dir];
    }
  }
  return result;
}

void PrintMatrix(const vector<vector<int>> &v) {
  for (int r = 0; r < v.size(); ++r) {
    for (int c = 0; c < v[r].size(); ++c) {
      cout << v[r][c] << ' ';
    }
    cout << endl;
  }
  return;
}

int main() {
  int n = 0;

  cout << "Enter n : " << flush;
  cin >> n;
  PrintMatrix(SpiralFill(n));

  return 0;
}

