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
    deque<int> elements;
public:
    void populate (TreeNode *root) {
        if (root->left) {
            populate(root->left);
        }
        elements.push_back(root->val);
        if (root->right) {
            populate(root->right);
        }
    }
    
    BSTIterator(TreeNode* root) {
        populate(root);        
    }
    
    int next() {
        int val = elements.front();
        elements.pop_front();
        return val;
    }
    
    bool hasNext() {
        return !elements.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

