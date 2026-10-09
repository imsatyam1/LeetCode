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
    void postOrder(TreeNode* root,vector<int> &vec){
        if(root == NULL) return;

        // postOrder(root -> left, vec);
        // postOrder(root -> right, vec);
        // vec.push_back(root -> val);

        // using 2 stack
        // stack<TreeNode*> st1, st2;
        // st1.push(root);
        // while(!st1.empty()){
        //     root = st1.top();
        //     st1.pop();
        //     st2.push(root);
        //     if(root -> left != NULL){
        //         st1.push(root -> left);
        //     }
        //     if(root->right != NULL){
        //         st1.push(root->right);
        //     }
        // }
        // while(!st2.empty()){
        //     vec.push_back(st2.top() -> val);
        //     st2.pop();
        // }

        // using 1 stack
        TreeNode* curr = root;
        stack<TreeNode*> st;
        
        while(!st.empty() || curr != NULL){
            if(curr != NULL){
                st.push(curr);
                curr = curr -> left;
            }
            else{
                TreeNode* temp = st.top() -> right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    vec.push_back(temp -> val);

                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        vec.push_back(temp->val);
                    }
                }
                else curr = temp;
            }
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        postOrder(root, vec);
        return vec;
    }
};