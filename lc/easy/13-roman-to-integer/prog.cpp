class Solution {
public:
    int romanToInt(string s) {
        int roman = 0;
        for (std::string::const_iterator i = s.begin();
            i != s.end();
            ++i) {
            switch (*i) {
                case 'V': roman += 5; continue;
                case 'L': roman += 50; continue;
                case 'D': roman += 500; continue;
                case 'M': roman += 1000; continue;
                case 'I':
                    if ((i+1) != s.end()) {
                        char c = * (i+1);
                        if (c == 'V') {
                            roman += 4;
                            ++i;
                        } else if (c == 'X') {
                            roman += 9;
                            ++i;
                        } else {
                            roman++;
                        }
                    } else {
                        roman++;
                    }
                    continue;
                case 'X':
                    roman += 10;
                    if ((i+1) != s.end()) {
                        char c = *(i+1);
                        if (c == 'L') {
                            roman += 30;
                            ++i;
                        } else if (c == 'C') {
                            roman += 80;
                            ++i;
                        }
                    }
                    continue;
                case 'C':
                    roman += 100;
                    if ((i+1) != s.end()) {
                        char c = *(i+1);
                        if (c == 'D') {
                            roman += 300;
                            ++i;
                        } else if (c == 'M') {
                            roman += 800;
                            ++i;
                        }
                    }
                    continue;
            }
        }
        return roman;
    }
};
