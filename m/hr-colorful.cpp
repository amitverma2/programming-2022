#include<iostream>
#include<unordered_set>
using namespace std;

bool IsColorful (int n) {
  unordered_set<int> products;
  string ns = to_string(n);
  for (int i = 1; i <= ns.size(); ++i) {
    for (int pos = 0; pos + i - 1 < ns.size(); ++pos) {
      int product = 1;
      for (int d = pos; d < pos + i; ++d) {
        product *= ns[d] - '0';
      }
      cout << "Debug : adding " << product << " to products\n";
      auto x = products.insert(product);
      if (!x.second)
        return false;
    }
  }
  return true;
}

int main () {
  int n;
  cin >> n;
  cout << (IsColorful(n)?"Colorful":"Not Colorful");
  cout << endl;
  return 0;
}
