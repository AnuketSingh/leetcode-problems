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
    ListNode* getIntersectionNode(ListNode* firsthead, ListNode* secondhead) {
     if(firsthead == NULL|| secondhead==NULL) return NULL;
    
    
       ListNode* temp1=firsthead;
        ListNode* temp2=secondhead;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(temp1==NULL)temp1=secondhead;
             if(temp2==NULL)temp2=firsthead;
        }
        return temp1;
    }
};
    