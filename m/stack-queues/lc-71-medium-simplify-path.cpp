class Solution {
public:
    string simplifyPath(string path) {
        deque<string> out;
        for (size_t i = 0; i != string::npos && i < path.length();) {
            // skip over /
            while (i < path.length() && path[i] == '/')
                i++;
            if (i == path.length())
                break;
            size_t next_slash = path.find('/', i);
            string cur;
            if (next_slash == string::npos) {
                cur = path.substr(i, next_slash);
            } else {
                cur = path.substr(i, next_slash - i);
            }
            if (cur == ".") {
                // no op
            } else if (cur == "..") {
                if (out.size() > 0) {
                    // cout << "Popping: " << out.back() << endl;
                    out.pop_back();
                }
            } else {
                out.push_back(cur);
                // cout << "Pushing: " << cur << endl;
            }
            i = next_slash;
        }
        string canonical = "/";
        while (!out.empty()) {
            canonical += out.front();
            out.pop_front();
            if (!out.empty()) {
                canonical += "/";
            }
        }
        return canonical;
    }
};

