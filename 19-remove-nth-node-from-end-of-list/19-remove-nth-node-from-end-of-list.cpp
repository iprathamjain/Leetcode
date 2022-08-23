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
        // if()
        ListNode* dummy=new ListNode(-1);
        dummy->next = head;
        ListNode* tmp=dummy;
        ListNode* a = dummy;
        if(head==NULL)
            return NULL;
        while(n--){
            if(tmp==NULL)
                return NULL;
            tmp = tmp->next;
        }
        
        while(tmp->next){
            a=a->next;
            tmp = tmp->next;
        }
        
        a->next=a->next->next;
        return dummy->next;
        
        
        
    }
};