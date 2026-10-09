/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int rowStart = 0;
        int colStart = 0;
        int rowEnd = m-1;
        int colEnd = n-1;
        int id = 0;

        while(rowStart <= rowEnd && colStart <= colEnd){
            if(id == 0){
                for(int i=colStart; head != NULL && i<=colEnd; i++){
                    ans[rowStart][i] = head -> val;
                    head = head -> next;
                }
                rowStart++;
            }

            if(id == 1){
                for(int i=rowStart; head != NULL && i<= rowEnd; i++){
                    ans[i][colEnd] = head -> val;
                    head = head -> next;
                }
                colEnd--;
            }

            if(id == 2){
                for(int i=colEnd; head != NULL && i>= colStart; i--){
                    ans[rowEnd][i] = head -> val;
                    head = head -> next;
                }
                rowEnd--;
            }

            if(id ==3){
                for(int i=rowEnd; head != NULL && i>= rowStart; i--){
                    ans[i][colStart] = head -> val;
                    head = head -> next;
                }
                colStart++;
            }

            id = (id+1)%4;
        }
        return ans;
    }
};