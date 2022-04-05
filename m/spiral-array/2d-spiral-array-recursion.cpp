#include<iostream>
using namespace std;

void SpiralFill(int *array, int n, int cur, int start_row, int start_col,
                int sz) {
  // array is a block of memory which stores the n*n array
  // this function will use sz*sz portion of this array
  // this portion left top position is start_row, and start_col
  // This function will fill the boundary of this portion, and then recurse
  if (sz > 0) {
    // Traverse the periphery of this block
    // First the top row, from left (start col) to right (start col + sz -1)
    for (int c = start_col; c < start_col + sz; ++c)
      *(array + start_row * n + c) = cur++;
    // Then the right column from top to bottom, start from next row as the right column first element is covered in the above loop for the top row
    for (int r = start_row + 1; r < start_row + sz; ++r)
      *(array + r * n + start_col + sz - 1) = cur++;
    // Then the bottom row from right col - 1 to left
    for (int c = start_col + sz - 1 - 1; c >= start_col; --c)
      *(array + (start_row + sz - 1) * n + c) = cur++;
    // The from bottom row - 1 to top row + 1 in the first column
    for (int r = start_row + sz - 1 - 1; r > start_row; --r)
      *(array + r * n + start_col) = cur++;
    // Recurse
    SpiralFill(array, n, cur, start_row + 1, start_col + 1, sz - 2);
  }
  return;
}

void PrintArray(int *array, int n) {
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      cout << *(array + r * n + c) << ' ';
    }
    cout << endl;
  }
  return;
}

int main() {
  int n = 0;
  cout << "Enter n: " << flush;
  cin >> n;

  int *array = new int[n*n];
  SpiralFill(array, n, 1, 0, 0, n);
  PrintArray(array, n);
  return 0;
}
