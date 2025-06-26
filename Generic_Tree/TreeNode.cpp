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
};

int main() {
    cout << "Creating a Tree : ";
    cout << "Enter the root Node : ";
    int val;
    cin >> val;
    TreeNode* root = new TreeNode(val);
    root->Construct();
    return 0;
}