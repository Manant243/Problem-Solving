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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* result = new ListNode();
        ListNode* prev = result;
        ListNode* temp = head;

        if(!temp->next) return temp;
        ListNode* current = new ListNode();

        while(temp && temp->next){
            current = temp->next;
            prev->next = current;
            temp->next = current->next;
            current->next = temp;
            prev = temp;
            temp = temp->next;
        }

        return result->next;
    }
};