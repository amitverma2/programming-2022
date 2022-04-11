/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // to start with
        if (!root) return result; // special case
        deque<pair<TreeNode*, int>> queue;      
        int d = 0;
        queue.push_back(make_pair(root, d));
        result.push_back(vector<int>());
        while (!queue.empty()) {
            auto [node, depth] = queue.front();
            queue.pop_front();
            if (depth == d) {
                result[depth].push_back(node->val);
            } else {
                result.push_back(vector<int>());
                d = depth;
                result[depth].push_back(node->val);
            }
            if (node->left) {
                queue.push_back(make_pair(node->left, depth+1));
            }
            if (node->right) {
                queue.push_back(make_pair(node->right, depth+1));
            }
        }
        return result;
    }
};
