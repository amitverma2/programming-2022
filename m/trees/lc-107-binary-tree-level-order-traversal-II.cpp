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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if (!root) return results; // Empty vector
        deque<TreeNode *> pipeline;
        pipeline.push_back(root);
        unordered_map<TreeNode*, int> levels;
        levels[root] = 0;
        int cur_level = -1;
        while (!pipeline.empty()) {
            TreeNode *cur = pipeline.front();
            pipeline.pop_front();
            int level = levels[cur];
            if (cur_level != level) {
                cur_level = level;
                results.push_back(vector<int>());
            }
            results.back().push_back(cur->val);
            if (cur->left) {
                pipeline.push_back(cur->left);
                levels[cur->left] = cur_level + 1;
            }
            if (cur->right) {
                pipeline.push_back(cur->right);
                levels[cur->right] = cur_level + 1;
            }
        }
        reverse(results.begin(), results.end());
        return results;
    }
};

