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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead=new ListNode(-1);
        ListNode* curr=dummyhead;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1 || temp2){
        int sum=0;
            if(temp1!=nullptr){ 
                sum+=temp1->val;
                temp1=temp1->next;
                }
            if(temp2!=nullptr){
                sum+=temp2->val;
                temp2=temp2->next;
            } 
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            cout<<"carry: "<<carry<<"\n";
            cout<<"sum: "<<sum<<"\n";
            ListNode* add=new ListNode(sum);
            curr->next=add;
            curr=curr->next;
        }
        if(carry){
            ListNode* add=new ListNode(carry);
            curr->next=add;
        }
        return dummyhead->next;
    }
};