class Solution {
public:
    ListNode* reversell(ListNode* s){
        ListNode *c=s,*p=NULL,*n;
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    
    
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *slow=head, *fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* rev=reversell(slow->next);
        ListNode* curr=head;
        while(rev!=NULL){
            if(rev->val!=curr->val)
                return false;
            rev=rev->next;
            curr=curr->next;
        }
        return true;
    }
};