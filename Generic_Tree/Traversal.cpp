#include <iostream>
#include <vector>
#include <queue>
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
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // LNR
        // L
        inorder(root -> left);
        cout << root -> val << endl;
        // R
        preorder(root -> right);
    }
    void postorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // LRN
        // L
        postorder(root -> left);
        // R
        postorder(root -> right);
        cout << root -> val << endl;
    }
    void levelorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == NULL) {
                cout << endl;
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
                cout << front -> val;
                if (front -> left != NULL) {
                    q.push(front -> left);
                }
                if (front -> right != NULL) {
                    q.push(front -> right);
                }
            }
        }
    }
};

int main() {
    TreeNode* root;
    root->Construct();
    root -> preorder(root);
    return 0;
}
