#include <bits/stdc++.h>
using namespace std;

void print_array (const vector<int> &arr, int l, int r) {
  for (int i = l; i < r; ++i)
    cout << arr[i] << ((i == r - 1)?'\n':' ');
}

void partition (vector<int> &arr, int l, int r, int &i, int &j) {
  int pivot = arr[l];
  vector<int> left;
  vector<int> equal;
  vector<int> right;
  for (int p = l; p < r; p++) {
    if (arr[p] == pivot)
      equal.push_back(arr[p]);
    else if (arr[p] < pivot)
      left.push_back(arr[p]);
    else
      right.push_back(arr[p]);
  }
  i = l + left.size();
  j = l + left.size() + equal.size();
  int p = l;
  for (auto x : left)
    arr[p++] = x;
  for (auto x : equal)
    arr[p++] = x;
  for (auto x : right)
    arr[p++] = x;
}

void qsort (vector<int> &arr, int l, int r) {
  if (r - l <= 1) {
    return; // Array of 0 or 1 element is implicity sorted
  }
  int i, j;
  partition(arr, l, r, i, j);
  qsort(arr, l, i);
  qsort(arr, j, r);
  print_array(arr, l, r);
}

void quickSort(vector <int> &arr) {
  qsort(arr, 0, arr.size());
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
