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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1= new ListNode(-1);
        ListNode* head1 = l1;
        ListNode* l2= new ListNode(-1);
        ListNode* head2 = l2;
        ListNode* curr=head;
        while(curr){
            if(curr->val<x){
                head1->next=curr;
                head1=head1->next;
            }
            else{
                head2->next=curr;
                head2=head2->next;
            }
            curr=curr->next;
        }
        head2->next=NULL;
        head1->next=l2->next;
        return l1->next;
    }
};