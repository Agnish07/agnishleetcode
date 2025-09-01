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
    TreeNode* build(vector<int>& inorder,int is,int ie, vector<int>& postorder, int ps, int pe, map<int, int> &imap){
        if(ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int rootind = imap[root->val];
        int numsleft = rootind - is;


        root->left = build(inorder,is, rootind-1, postorder, ps, ps+numsleft-1, imap);
        root->right = build(inorder, rootind+1, ie, postorder, ps + numsleft, pe-1, imap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> imap;
        for(int i = 0; i < inorder.size(); i++){
            imap[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, imap);
    }
};