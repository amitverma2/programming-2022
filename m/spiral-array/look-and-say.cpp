#include<iostream>
#include<string>
using namespace std;

string GenerateNextLookAndSay(string s) {
  string result;
  if (s.size()) {
    // Some input is given
    int count = 0;
    char c = s.front();
    for (auto x = s.begin(); x != s.end(); ++x) {
      if (*x == c) {
        ++count;
      } else {
        result += to_string(count);
        result += c;
        c = *x;
        count = 1;
      }
    }
    result += to_string(count);
    result += c;
  }
  return result;
}

int main() {
  int n;
  cout << "How many look and say terms to generate: " << flush;
  cin >> n;

  string s = "1";
  while (n-- > 0) {
    cout << s << endl;
    s = GenerateNextLookAndSay(s);
  }
  return 0;
}
