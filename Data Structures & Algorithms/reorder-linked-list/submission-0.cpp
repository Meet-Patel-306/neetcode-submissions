class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        ListNode* curr = head;

        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int i = 0;
        int j = nodes.size() - 1;

        while (i < j) {
            nodes[i]->next = nodes[j];
            i++;

            if (i == j) break;

            nodes[j]->next = nodes[i];
            j--;
        }

        nodes[i]->next = nullptr;
    }
};