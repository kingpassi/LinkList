/******************************************************************************
 Palindrome Linked List
 
 Given the head of a singly linked list, return true if it is a palindrome.
 
Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*******************************************************************************/
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reversell(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
            if(slow->val!=head->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
        
        
        
    }
    
    ListNode*reversell(ListNode*head){
        ListNode*prev=NULL;
        ListNode*slow=head;
        ListNode*fast;
        
        while(slow!=NULL){
            fast=slow->next;
            slow->next=prev;
            
            prev=slow;
            slow=fast;
        }
        head=prev;
        return head;
        
    }
      
};