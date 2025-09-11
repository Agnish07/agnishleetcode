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
    void inorder(TreeNode* root, int k, int &cnt, int &ks){
        if(root == NULL || k <= cnt) return;

        inorder(root->left, k,cnt, ks);
        cnt++;

        if(cnt == k) {
            ks = root->val;
            return;
        } 

        inorder(root->right, k, cnt, ks);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ks = INT_MAX;
        int cnt = 0;
        inorder(root,k,cnt,ks);

        return ks;
    }
};