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
    void inOrder(TreeNode* root, vector<int> &vec){
        if(root == NULL) return;

        // =====Recursive Approch======
        // inOrder(root -> left, vec);
        // vec.push_back(root-> val);
        // inOrder(root->right, vec);

        // ======Itterative Approch======
        stack<TreeNode*> st;
        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root -> left;
            }
            root =  st.top();
            st.pop();
            vec.push_back(root -> val);
            root = root -> right;
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inOrder(root,vec);
        return vec;
    }
};