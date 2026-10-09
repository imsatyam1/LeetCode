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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL){
            count++;
            curr =curr -> next;
        }
        int eachBucketList = count/k;
        int reminderNode = count%k;

        vector<ListNode*> ans(k, NULL);

        curr = head;
        ListNode* prev = NULL;

        for(int i=0; curr && i<k; i++){
            ans[i] = curr;

            for(int j=1; j<= eachBucketList + (reminderNode > 0 ? 1:0); j++){
                prev = curr;
                curr = curr -> next;
            }
            if(prev != NULL){
                prev -> next = NULL;
            }
            reminderNode--;
        }
        return ans;
    }
};