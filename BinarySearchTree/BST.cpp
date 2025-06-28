#include <iostream>
#include <queue>
using namespace  std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val == data;
        left = NULL;
        right = NULL;
    }
    TreeNode* bst(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return root;
        }
        else {
            if (val < root -> val) {
                root -> left = bst(root -> left, val);
            }
            else {
                root -> right = bst(root -> right, val);
            }
        }
        return root;
    }
    void createNode(TreeNode* root) {
        int val;
        cout << "Enter the value of node : ";
        cin >> val;
        while (val != -1) {
            bst(root, val);
            cout << "Enter the value of node : ";
            cin >> val;
        }
    }
    void levelorder(TreeNode* root) {
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
            cout << front -> val;
            levelorder(root -> left);
            levelorder(root -> right);
        }
    }
};
int main() {
    TreeNode* root = NULL;
    root -> createNode(root);
    root -> levelorder(root);
    return 0;
}