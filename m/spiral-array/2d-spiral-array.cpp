#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> spiral(int n) {
  vector<vector<int>> out(n+2);
  for (int i = 0; i <= n+1; ++i) {
    out[i].resize(n+2);
  }
  // set boundaries
  for (int i = 0; i <= n+1; ++i) {
    out[0][i] = out[n+1][i] = out[i][0] = out[i][n+1] = 1;
  }
  for(int i = 0; i <= n+1; ++i) {
    for(int j = 0; j <= n+1; ++j) {
      cout << out[i][j] << ' ';
    }
    cout << endl;
  }
  int x = 1;
  int y = 1;
  int dir = 0; // 0 is going right, 1 going down, 2 going left, 3 going up 
  int cur = 1;
  while (cur <= n*n) {
    out[x][y] = cur;
    cur++;
    switch (dir) {
      case 0: y++; break;
      case 1: x++; break;
      case 2: y--; break;
      case 3: x--; break;
    }
    if (out[x][y]) {
      // we hit edge
      switch(dir) {
        case 0: y--; dir=1; x++; break;
        case 1: x--; dir=2; y--; break;
        case 2: y++; dir=3; x--; break;
        case 3: x++; dir=0; y++; break;
      }
    }
  }
  vector<vector<int>> result(n);
  for(int i = 0; i < n; ++i) {
    result[i].resize(n);
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      result[i][j] = out[i+1][j+1];
    }
  }
  return result;
}

int main() {
  int n = 8;
  vector<vector<int>> result = spiral(n);
  cout << "Output\n";
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}

