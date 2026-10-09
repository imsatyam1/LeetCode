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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return nullptr;

        queue<TreeNode*> q;
        vector<int> levelSum;

        q.push(root);
        while(!q.empty()){
            int size= q.size();
            int totalSum = 0;

            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                totalSum += temp -> val;

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            levelSum.push_back(totalSum);
            totalSum = 0;
        }

        q.push(root);
        root -> val = 0;
        int i = 1;

        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                int simblingSum = (curr -> left)?curr -> left -> val: 0;
                simblingSum += (curr -> right)?curr -> right -> val:0;

                if(curr -> left){
                    curr -> left -> val = levelSum[i] - simblingSum;
                    q.push(curr -> left);
                }

                if(curr -> right){
                    curr -> right -> val = levelSum[i] - simblingSum;
                    q.push(curr -> right);
                }
            }
            i++;
        }
        return root;
    }
};