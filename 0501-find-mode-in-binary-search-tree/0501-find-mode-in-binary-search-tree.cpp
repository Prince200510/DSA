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
    unordered_map<int, int> freq;

    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        freq[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if(root == NULL) {
            return{};
        }

        dfs(root);
        int mx = 0;

        vector<int> ans;
        for(auto &it : freq) {
            mx = max(mx, it.second);
        }

        for(auto &it : freq) {
            if(it.second == mx) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};