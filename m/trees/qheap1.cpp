#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sift_down(vector<int> &heap, int i) {
    int last = heap.size() - 1;
    while (true) {
        if (2*i + 2 <= last) {
            int branch = (heap[2*i + 1] < heap[2*i + 2])?(2*i + 1):(2*i + 2);
            if (heap[i] > heap[branch]) {
                int temp = heap[i];
                heap[i] = heap[branch];
                heap[branch] = temp;
                i = branch;
            } else {
                break; // we are done
            }
        } else if (2*i + 1 <= last) {
            int branch = 2*i + 1;
            if (heap[i] > heap[branch]) {
                int temp = heap[i];
                heap[i] = heap[branch];
                heap[branch] = temp;
                i = branch;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

void sift_up(vector<int> &heap) {
    int i = heap.size() - 1;
    while (i > 0) {
        int parent = (i-1)/2;
        if (heap[i] < heap[parent]) {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin >> Q;
    vector<int> heap;
    while (Q-- > 0) {
        int cmd;
        cin >> cmd;
        switch (cmd) {
            case 1: // add a num
            {
                int v;
                cin >> v;
                heap.push_back(v);
                sift_up(heap);
                break;
            }
            case 2: // delete a num
            {
                int v;
                cin >> v;
                // v is guaranteed to be found
                // heap can be single element also
                if (heap.size() == 1) {
                    heap.pop_back();
                } else {
                    // find where is v
                    int i;
                    for (i = 0; i < heap.size(); ++i) {
                        if (heap[i] == v)
                            break;
                    }
                    if (i == heap.size() - 1) {
                        // v was last element
                        heap.pop_back();
                    } else {
                        int last = heap.back();
                        heap.pop_back();
                        heap[i] = last;
                        sift_down(heap, i);
                    }
                }
                break;
            }
            case 3: // print min
                if (!heap.empty()) {
                    cout << heap[0] << endl;
                }
                break;
        }
    }
    return 0;
}

