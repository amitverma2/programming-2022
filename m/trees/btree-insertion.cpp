

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        if (!root) return new Node(data);
        
        if (data < root->data) {
            if (!root->left) {
                root->left = new Node(data);
            } else {
                insert(root->left, data);
            }
        } else {
            if (!root->right) {
                root->right = new Node(data);
            } else {
                insert(root->right, data);
            }            
        }
        return root;
    }


