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
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1 -> val <= list2 -> val)
            {
                tail -> next = list1;
                list1 = list1 -> next;
            }
            else
            {
                tail -> next = list2;
                list2 = list2 -> next;
            }
            tail = tail -> next;
        }

        if(list1 != nullptr) tail -> next = list1;
        else tail -> next = list2;

        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* result = nullptr;

        for(int i=0; i<lists.size(); i++)
        {
            result = mergeTwoList(result, lists[i]);
        }

        return result;
    }
};