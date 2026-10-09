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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1 == nullptr && list2 == nullptr) return nullptr;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* newHead = nullptr;
        ListNode* newNode = nullptr;

        if(temp1 -> val <= temp2 -> val)
        {
            newHead = new ListNode(temp1->val);
            
            temp1 = temp1 -> next;
        }
        else
        {
            newHead = newHead = new ListNode(temp2->val);;
            
            temp2 = temp2 -> next;
        }

        newNode = newHead;

        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1 -> val <= temp2 -> val)
            {
                ListNode* temp = new ListNode(temp1 -> val);
                newNode -> next = temp;
                newNode = temp;

                temp1 = temp1 -> next;
            }
            else
            {
                ListNode* temp = new ListNode(temp2 -> val);
                newNode -> next = temp;
                newNode = temp;

                temp2 = temp2 -> next;
            }
        }

        while(temp1 != nullptr)
        {
            ListNode* temp = new ListNode(temp1 -> val);
            newNode -> next = temp;
            newNode = temp;

            temp1 = temp1 -> next;
        }

        while(temp2 != nullptr)
        {
            ListNode* temp = new ListNode(temp2 -> val);
            newNode -> next = temp;
            newNode = temp;

            temp2 = temp2 -> next;
        }

        return newHead;
    }
};