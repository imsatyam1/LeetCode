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
    int gcd(int a, int b){
        int result = min(a, b);
        while(result >0){
            if(a%result == 0 && b%result == 0){
                break;
            }
            result--;
        }
        return result;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        ListNode* forward = head -> next;

        if(head == NULL || head -> next == NULL){
            return head;
        }

        while(forward != NULL){
            ListNode* dummy = new ListNode(-1);
            int a = temp -> val;
            int b = forward -> val;
            int gcdValue = gcd(a, b);
            dummy -> val = gcdValue;
            temp -> next = dummy;
            dummy -> next = forward;

            temp = temp -> next -> next;
            forward = forward -> next;
        }
        return head;
    }
};