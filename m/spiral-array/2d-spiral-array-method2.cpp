#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> SpiralFill(int n) {
  vector<vector<int>> temp(n+2); // create a vector with two additional rows for markers
  for (int r = 0; r < n+2; ++r) {
    temp[r].resize(n+2); // make each vector in the row to be n+2 colums, as we need column markers also
  }
  // setup markers of 1
  for (int i = 0; i < n + 2; ++i) {
    temp[0][i] = temp[n+1][i] = 1; // each column of 0'th and n+1'th row
    temp[i][0] = temp[i][n+1] = 1; // each row of 0'th and n+1'th column
  }
  // Where am I
  int x = 1;
  int y = 1;
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
    temp[x][y] = cur;
    // Update next value to fill
    ++cur;
    // Move to next position based on current direction
    x += dr[dir];
    y += dc[dir];
    // Check if I've run into a wall/filled cell
    if (temp[x][y]) {
      // We've hit a wall/filled cell, change directions
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
  // Take the middle array to be returned
  // Create a n * n array
  vector<vector<int>> result(n);
  for (int r = 0; r < n; ++r) {
    result[r].resize(n);
  }
  // Copy the output into this
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      result[r][c] = temp[r + 1][c + 1];
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

