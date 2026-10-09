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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr)
        {
            ListNode* next = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k)
    {
        k -= 1;

        while(temp != nullptr && k > 0)
        {
            k--;
            temp = temp -> next;
        }

        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while(temp != nullptr)
        {
            ListNode* KthNode = findKthNode(temp, k);
            if(KthNode == nullptr)
            {
                if(prevNode)
                {
                    prevNode  -> next = temp;
                }
                break;
            }

            ListNode* nextNode = KthNode -> next;
            KthNode -> next = nullptr;

            reverseList(temp);

            if(temp == head)
            {
                head = KthNode;
            }
            else
            {
                prevNode -> next = KthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};