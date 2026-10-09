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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> vec;
            for(int i=0; i<n; i++){
                TreeNode* temp =q.front();
                q.pop();
                vec.push_back(temp);

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }

            if(count%2 == 1){
                int l = 0, r=vec.size()-1;

                while(l < r){
                    int tempVal = vec[l] -> val;
                    vec[l] -> val = vec[r] -> val;
                    vec[r] -> val = tempVal;
                    l++;
                    r--;
                }
            }
            count++;
        }
        return root;
    }
};