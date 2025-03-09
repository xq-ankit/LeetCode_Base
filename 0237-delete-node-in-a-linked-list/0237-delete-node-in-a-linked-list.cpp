/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode* temp = node->next; // Store next node
        node->val = temp->val;     // Copy value of next node
        node->next = temp->next;   // Skip the next node
        delete temp; // Free memory of the removed node
    }
};