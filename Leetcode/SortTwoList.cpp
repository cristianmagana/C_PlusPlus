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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        
        ListNode *head = nullptr, *tail = nullptr;
        if(l1->val <= l2->val) {
            head = tail = l1;
            l1 = l1->next;
        }
        else {
            head = tail = l2;
            l2 = l2->next;
        }
        
        ListNode * c1 = l1, *c2 = l2;
        while (c1 != nullptr && c2 != nullptr) {
            
            if(c1->val <= c2->val){
                tail->next = c1;
                tail = c1;
                c1 = c1->next;
            }
            else {
                tail->next = c2;
                tail = c2;
                c2 = c2->next;
            }
        }
        if(c1 == nullptr) {
            tail->next = c2;
        }
        else {
            tail->next = c1;
        }
        return head;
    }
};
