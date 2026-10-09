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
    void preOrder(TreeNode* root, vector<int> &vec){

        // ======Recursive approch=====
        // if(root == NULL) return;
        // vec.push_back(root-> val);
        // preOrder(root -> left, vec);
        // preOrder(root->right, vec);

        // ======Iterative Approch=====
        if(root == NULL) return;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();

            vec.push_back(root -> val);

            if(root -> right != NULL){
                st.push(root -> right);
            }
            if(root -> left != NULL){
                st.push(root -> left);
            }
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preOrder(root,vec);
        return vec;
    }
};