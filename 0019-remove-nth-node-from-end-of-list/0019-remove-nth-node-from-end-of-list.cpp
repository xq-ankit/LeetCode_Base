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
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==n){
            return head->next;
        }
        count-=n;
        temp=head;
        while(temp){
            count--;
            if(count==0){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
        }
        return head;

    }
};