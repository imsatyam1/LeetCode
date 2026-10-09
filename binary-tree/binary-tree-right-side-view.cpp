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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;

        if(root == NULL) return ans;

        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* temp = it.first;
            int line = it.second;

            mp[line] = temp -> val;

            if(temp -> left) q.push({temp -> left, line +1});
            if(temp -> right) q.push({temp -> right, line+1});
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};