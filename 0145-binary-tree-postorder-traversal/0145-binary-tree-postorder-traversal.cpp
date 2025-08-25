class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            // If right child doesn't exist or already visited
            if (curr->right == nullptr || curr->right == prev) {
                result.push_back(curr->val);
                st.pop();
                prev = curr;
                curr = nullptr; // prevent re-traversing
            } else {
                curr = curr->right;
            }
        }

        return result;
    }
};
