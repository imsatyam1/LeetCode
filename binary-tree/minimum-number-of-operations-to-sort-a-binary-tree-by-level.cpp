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
    int countoperation(vector<int> &vec){
        int count = 0;
        vector<int> sortedvec(vec.begin(), vec.end());

        sort(begin(sortedvec), end(sortedvec));

        unordered_map<int, int> mp;

        for(int i=0; i<vec.size(); i++){
            mp[vec[i]] = i;
        }

        for(int i=0; i<vec.size(); i++){
            if(vec[i] == sortedvec[i]) continue;

            int currIndx = mp[sortedvec[i]];
            mp[vec[currIndx]] = i;
            mp[vec[i]] = currIndx;

            swap(vec[i], vec[currIndx]);
            count++;
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        int result = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> vec;

            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                vec.push_back(temp -> val);

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            result += countoperation(vec);
        }
        return result;
    }
};