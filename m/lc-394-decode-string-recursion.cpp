class Solution {
public:
    string decodeRecursive(string &s, int cur, int &inc) {
        if (cur >= s.length()) { inc = 0; return ""; }
        string result;
        inc = 0;
        while (cur < s.length()) {
            if (isdigit(s[cur])) {
                int k = 0;
                while (isdigit(s[cur])) {
                    k *= 10;
                    k += s[cur] - '0';
                    cur++; inc++;
                }
                // cur should be at a '[' skip it
                cur++; inc++;
                // recurse and find the string to repeat;
                int move;
                string rep = decodeRecursive(s, cur, move);
                for (int i = 0; i < k; ++i) {
                    result += rep;
                }
                inc += move;
                cur += move;
            } else if (isalpha(s[cur])) {
                result += s[cur];
                cur++;
                inc++;
            } else if (s[cur] == ']') { //only remaining option
                inc++;
                cur++;
                return result;
            } else {
                cout << "WTF\n";
                cur++;
                inc++;
            }
        }
        return result;
    }
    string decodeString(string s) {
        int inc;
        return decodeRecursive(s, 0, inc);
    }
};

