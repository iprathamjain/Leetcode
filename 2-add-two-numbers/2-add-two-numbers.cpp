// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };

class Solution {
public:
    
    
    void insertattail(ListNode* &head,ListNode* &tail,int d){
        ListNode* temp=new ListNode(d);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    ListNode* add(ListNode* l11, ListNode* l21){
        int carry=0;
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;
        
        while(l11!=NULL or l21!=NULL or carry!=0){
            int val1=0;
             if(l11!=NULL)
                 val1=l11->val;
            
            int val2=0;
             if(l21!=NULL)
                 val2=l21->val;
            
            int sum=carry+val1+val2;
            
            int digit=sum%10;
            insertattail(anshead, anstail, digit);
            carry=sum/10;
            
            if(l11!=NULL)
                l11=l11->next;
            if(l21!=NULL)
                l21=l21->next;
            
        }
        return anshead;
    }
    ListNode* reversell(ListNode *head){
        ListNode *prev=NULL, *curr=head, *next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reversell(l1);
        // l2=reversell(l2);
        
        ListNode* final = add(l1,l2);
        // final=reversell(final);
        
        return final;
        
        
    }
};