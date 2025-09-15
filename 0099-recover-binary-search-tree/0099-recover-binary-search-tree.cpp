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
TreeNode* prev;
TreeNode* f;
TreeNode* m;
TreeNode* l;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL && (prev->val > root->val)){

            if(f == NULL){
                f = prev;
                m = root;
            }

            else{
                l = root;
            }
        }

        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        f = m = l = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(f && l) swap(f->val, l->val);
        else if(f && m) swap(m->val, f->val);
    }
};