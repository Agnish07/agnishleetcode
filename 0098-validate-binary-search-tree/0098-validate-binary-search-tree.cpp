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
class Solution {
public:
    bool isv(TreeNode* root, long long minv, long long maxv){
        if(root == NULL) return true;

        if(minv >= root->val || maxv <= root->val) return false;

        return isv(root->left, minv, root->val) && isv(root->right, root->val, maxv);
    }
    bool isValidBST(TreeNode* root) {

        return isv(root, LLONG_MIN, LLONG_MAX);
    }
};