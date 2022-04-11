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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == 0) return result; // special case
        
        deque<pair<TreeNode*, int>> queue;
        int depth = 0;
        bool lr = true;
        queue.push_back(make_pair(root, depth));
        result.push_back(vector<int>());
        while (!queue.empty()) {
            auto [node, cur_depth] = queue.front();
            queue.pop_front();
            if (cur_depth == depth) {
                result[depth].push_back(node->val);
            } else {
                if (!lr) reverse(result[depth].begin(), result[depth].end());
                lr = !lr;
                result.push_back(vector<int>());
                depth = cur_depth;
                result[depth].push_back(node->val);
            }
            if (node->left)     queue.push_back(make_pair(node->left, depth+1));
            if (node->right)    queue.push_back(make_pair(node->right, depth+1));
        }
        if (!lr) reverse(result[depth].begin(), result[depth].end());
        return result;
    }
};

