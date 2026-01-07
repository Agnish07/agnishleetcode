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
    long long totsum = 0;
    long long maxi = 0;
    int maxProduct(TreeNode* root) {
        totsum = subsum(root);
        subsum(root);
        return maxi % 1000000007;
    }
    int subsum(TreeNode* node){
        if(!node) return 0;
        long long sum = node->val + subsum(node->left) + subsum(node->right);
        if(totsum > 0){
            maxi = max(maxi, sum * (totsum-sum));
        }
        return sum;
    }
};