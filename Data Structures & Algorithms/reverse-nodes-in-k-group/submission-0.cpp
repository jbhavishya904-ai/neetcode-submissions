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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check whether at least k nodes are available
        ListNode* temp = head;

        for (int i = 0; i < k; i++) {
            if (temp == nullptr)
                return head;  // Fewer than k nodes: don't reverse
            temp = temp->next;
        }

        // Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // head is now the last node of the reversed group
        head->next = reverseKGroup(curr, k);

        // prev is the new head of this group
        return prev;
    }
};
