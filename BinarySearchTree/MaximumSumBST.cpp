#include <iostream>
#include <climits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Info
{
public:
    int minval;
    int maxval;
    int isB;
    int sum;
};
Info solve(TreeNode *root, int &sum)
{
    if (root == NULL)
    {
        Info temp;
        temp.minval = INT_MAX;
        temp.maxval = INT_MIN;
        temp.sum = 0;
        temp.isB = true;
        sum = max(sum, temp.sum);
        return temp;
    }
    // LRN
    Info leftA = solve(root->left, sum);
    Info rightA = solve(root->right, sum);
    // Node
    Info currA;
    currA.minval = min(leftA.minval, min(rightA.minval, root->val));
    currA.maxval = max(leftA.maxval, max(rightA.maxval, root->val));
    currA.isB = (root->val > leftA.maxval && root->val < rightA.minval &&
                 leftA.isB && rightA.isB);
    currA.sum = leftA.sum + rightA.sum + root->val;
    if (currA.isB)
    {
        sum = max(sum, currA.sum);
    }
    return currA;
}
int maxSumBST(TreeNode *root)
{
    int sum = 0;
    Info temp = solve(root, sum);
    return sum;
}