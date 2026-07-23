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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t = head;
        int l = 0;
        while(t!=nullptr){
            t = t->next;
            l++;
        }
        t = head;
        if(l == n) return head->next;
        for(int i = 1;i<l-n;i++){
            t = t->next;
        }
        t->next = t->next->next;
        return head;
    }
};
