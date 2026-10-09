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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        int count = 1;
        dq.push_back(root);

        while(!dq.empty()){
            if(count%2 != 0){
                int size = dq.size();
                vector<int> vec; 
                for(int i=0; i<size; i++){
                    TreeNode* temp = dq.front();
                    dq.pop_front();
                    vec.push_back(temp -> val);

                    if(temp -> left) dq.push_back(temp -> left);
                    if(temp -> right) dq.push_back(temp -> right);
                }
                ans.push_back(vec);
                count++;
            }
            else{
                int size = dq.size();
                vector<int> vec; 
                for(int i=0; i<size; i++){
                    TreeNode* temp = dq.back();
                    dq.pop_back();
                    vec.push_back(temp -> val);

                    if(temp -> right) dq.push_front(temp -> right);
                    if(temp -> left) dq.push_front(temp -> left);
                }
                ans.push_back(vec);
                count++;
            }
        }
        return ans;
    }
};