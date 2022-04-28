/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        deque<Node*> currentLevel;
        if (!root) return root;
        currentLevel.push_back(root);
        while (!currentLevel.empty()) {
            Node * prev = 0;
            deque<Node*> nextLevel;
            while (!currentLevel.empty()) {
                Node * n = currentLevel.front();
                currentLevel.pop_front();
                if (prev) {
                    prev->next = n;
                }
                prev = n;
                if (n->left) nextLevel.push_back(n->left);
                if (n->right) nextLevel.push_back(n->right);
            }
            swap(currentLevel, nextLevel);
        }
        return root;
    }
};

