/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentfinder(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parents[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right){
                parents[curr->right] = curr;
                q.push(curr->right);
            }

        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, bool> vis;
        unordered_map<TreeNode*, TreeNode*> parents;
        parentfinder(root, parents);
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist++ == k) break;
            for(int i = 0 ; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                if(parents[curr] && !vis[parents[curr]]){
                    q.push(parents[curr]);
                    vis[parents[curr]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            ans.push_back(cur->val);
        }
        return ans;
    }
};