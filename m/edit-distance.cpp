#include<iostream>
#include<string>
#include<map>
using namespace std;

multimap<char, int> GetStringMmap(string &s) {
  multimap<char, int> mm;
  for (int i = 0; i < s.size(); ++i) {
    mm.insert(make_pair(s[i], i));
  }
  return mm;
}

int FindEditDistance(multimap<char, int> &m1, multimap<char, int> &m2) {
  int count = 0;
  // We made sure m1 > m2
  for (auto x = m1.begin(); x != m1.end(); ++x) {
    auto m2f = m2.equal_range(x->first);
    bool match = false;
    for (auto i = m2f.first; i != m2f.second; ++i) {
      if (i->second == x->second) {
        match = true;
        break;
      }
    }
    if (!match) count++;
  }
  return count;
}

int EditDistanceCalculate(string &s1, string &s2) {
  if (s2.size() > s1.size()) s2.swap(s1);
  multimap<char, int> s1m;
  multimap<char, int> s2m;
  s1m = GetStringMmap(s1);
  s2m = GetStringMmap(s2);
  int distance = FindEditDistance(s1m, s2m);
  return distance;
}

int main() {
  string s1;
  string s2;
  cout << "Enter two strings: " << flush;
  cin >> s1;
  cin >> s2;

  int distance = EditDistanceCalculate(s1, s2);
  if (distance > 1)
    cout << "More than one edit distance. (" << distance << ")\n";
  else if (distance < 1)
    cout << "Less than one edit distance. (" << distance << ")\n";
  else
    cout << "Edit distance is one.\n";
  return 0;
}
