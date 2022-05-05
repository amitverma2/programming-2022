/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // handle no node case;

        array<Node*, 101> cloned;
        array<bool, 101> visited;

        cloned.fill(0);
        visited.fill(false);

        queue<Node*> pipeline;      
        pipeline.push(node);
        visited[node->val] = true;
        cloned[node->val] = new Node(node->val);
        while (!pipeline.empty()) {
            Node* cur = pipeline.front();
            pipeline.pop();
            for (auto x : cur->neighbors) {
                if (!visited[x->val]) {
                    visited[x->val] = true;
                    pipeline.push(x);
                    cloned[x->val] = new Node(x->val);
                }
                cloned[cur->val]->neighbors.push_back(cloned[x->val]);
            }
        }
        return cloned[node->val];
    }
};

