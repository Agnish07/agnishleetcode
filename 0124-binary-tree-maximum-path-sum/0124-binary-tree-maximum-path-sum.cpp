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
    int maxv = INT_MIN;
    int maxp(TreeNode* root){
        if(root == NULL) return 0;

        int lv = max(0,maxp(root->left));
        int rv = max(0, maxp(root->right));

        maxv = max(lv + rv + root->val, maxv);
        return root->val + max(lv, rv); 
    }
    int maxPathSum(TreeNode* root) {
        maxp(root);
        return maxv;
    }
};