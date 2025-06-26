#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this -> val = data;
        left = NULL;
        right = NULL;
    }
    TreeNode* Construct() {
        cout << "Enter the value : ";
        int val;
        cin >> val;
        if (val == -1) {
            return NULL;
        }
        else {
            TreeNode* root = new TreeNode(val);
            // Recursion
            cout << "Left child of : " << val << endl;
            root -> left = Construct();
            cout << "Right child of : " << val << endl;
            root -> right = Construct();
        }
    }
    void preorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // NLR
        cout << root -> val << endl;
        // L
        preorder(root -> left);
        // R
        preorder(root -> right);
    }
};

int main() {
    TreeNode* root;
    root->Construct();
    root -> preorder(root);
    return 0;
}
