#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    vector<int> input_stack;
    vector<int> output_stack;
    while (q-- > 0) {
        int cmd;
        cin >> cmd;
        switch (cmd) {
            case 1: {
                int x;
                cin >> x;
                input_stack.push_back(x);
            }
            break;
            case 2: {
                      if (output_stack.empty()) {
                        while (!input_stack.empty()) {
                          output_stack.push_back(input_stack.back());
                          input_stack.pop_back();
                        }
                      }
                      output_stack.pop_back();
                    }
                    break;
            case 3: {
                      if (output_stack.empty()) {
                        while (!input_stack.empty()) {
                          output_stack.push_back(input_stack.back());
                          input_stack.pop_back();
                        }
                      }
                      cout << output_stack.back() << endl; break;
                    }
        }
    }
    return 0;
}

