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
class BSTIterator {
    stack<TreeNode*> levels;
public:
    void populate (TreeNode *root) {
        if (!root) return;
        
        levels.push(root);
        if (root->left) {
            populate(root->left);
        }
    }
    
    BSTIterator(TreeNode* root) {
        populate(root);        
    }
    
    int next() {
        TreeNode* cur = levels.top();
        levels.pop();
        if (cur->right)
            populate(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !levels.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

