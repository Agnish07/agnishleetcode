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
    int fn(TreeNode* root, int temp){
        if(root == NULL){
            return 0;
        }

        temp = (temp << 1) + root->val;

        if(root->left == NULL && root->right == NULL)return temp;
        
        int left = fn(root->left, temp);
        int right = fn(root->right, temp);

        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        return fn(root, 0);
    }
};