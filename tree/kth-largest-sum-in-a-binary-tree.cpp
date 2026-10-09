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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum;
         int count =0;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            sum = 0;

            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp -> val;
                
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right); 
            }
            count++;
            pq.push(sum);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return (count >= k)?pq.top():-1;
    }
};