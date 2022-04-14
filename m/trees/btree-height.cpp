
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if (!root || (!root->left && !root->right)) return 0;
        int l_height = height(root->left);
        int r_height = height(root->right);
        return ((l_height > r_height)?l_height:r_height) + 1;
    }


