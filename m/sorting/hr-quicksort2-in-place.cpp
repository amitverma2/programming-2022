#include <bits/stdc++.h>
using namespace std;

void print_array (const vector<int> &arr, int l, int r) {
  for (int i = l; i < r; ++i)
    cout << arr[i] << ((i == r - 1)?'\n':' ');
}

void swap(vector<int> &arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition (vector<int> &arr, int l, int r) {
  int p = arr[l];
  int m = l;
  for (int i = l + 1; i < r; ++i) {
    if (arr[i] < p) {
      swap(arr, ++m, i);
    }
  }
  swap(arr, l, m);
  return m;
}

void qsort (vector<int> &arr, int l, int r) {
  if (r - l <= 1) {
    return; // Array of 0 or 1 element is implicity sorted
  }
  int m = partition(arr, l, r);
  qsort(arr, l, m);
  qsort(arr, m + 1, r);
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
