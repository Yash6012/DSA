#include <iostream>
using namespace std;

class Info
{
public:
    long long minval;
    long long maxval;
    bool isB;
};
Info solve(TreeNode *root)
{
    // Base Case
    if (root == NULL)
    {
        Info temp;
        temp.minval = LLONG_MAX;
        temp.maxval = LLONG_MIN;
        temp.isB = true;
        return temp;
    }
    // leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        Info temp;
        temp.minval = root->val;
        temp.maxval = root->val;
        temp.isB = true;
        return temp;
    }
    // LRN
    Info leftA = solve(root->left);
    Info rightA = solve(root->right);
    // Node
    Info currA;
    currA.minval = min(leftA.minval, min(rightA.minval, (long long)root->val));
    currA.maxval = max(leftA.maxval, max(rightA.maxval, (long long)root->val));
    currA.isB = (root->val > leftA.maxval && root->val < rightA.minval && leftA.isB && rightA.isB);
    return currA;
}
bool isValidBST(TreeNode *root)
{
    Info temp;
    temp = solve(root);
    return temp.isB;
}