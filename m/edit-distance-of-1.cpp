#include<iostream>
#include<string>
using namespace std;

bool HasEditDistanceOfOne(string &a, string &b) {
  if (a.size() > b.size()) a.swap(b);
  if (b.size() - a.size() > 1) return false;
  bool same_size = a.size() == b.size();
  auto i_a = a.begin();
  auto i_b = b.begin();
  int count = 0;
  cout << a << "," << b << " start of a: " << *i_a << " start of b: " << *i_b << endl;
  while (i_a != a.end()) {
    if (*i_a != *i_b) {
      cout << "Mismatch at " << *i_a << " & " << *i_b << endl;
      cout << " Incrementing count.. " << count << endl;
      ++count;
      if (count > 1) {
       cout << "Count exceeded 1. " << count << endl;
       return false;
      }
      if (!same_size) {
        cout << "Not Same size, so move only larger pointer ahead..." << endl;
        ++i_b;
      } else {
        cout << "Same size, so move both ahead..." << endl;
        ++i_a;
        ++i_b;
      }
    } else {
      cout << "Match at " << *i_a << " == " << *i_b << ", so move both ahead..." << endl;
      ++i_a; ++i_b;
    }
  }
  if (same_size) {
    return count == 1;
  } else {
    return count <= 1;
  }
}

int main(int argc, char *argv[]) {
  string a(argv[1]), b(argv[2]);
  if (HasEditDistanceOfOne(a, b))
    cout << "The strings are one edit apart...\n";
  else
    cout << "The strings are zero or more than one edit apart...\n";
  return 0;
}
