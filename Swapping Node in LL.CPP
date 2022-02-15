
 //Definition for singly-linked list.
 //Here Considered NULL as 0;
 struct ListNode {
     int val;
     ListNode *next;
     
     ListNode() : val(0), next(0) {}
     ListNode(int x){
        this -> val = x;
        this -> next = 0;
     }     
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {

private: 
    
    ListNode* swap(ListNode* &head, ListNode* start, ListNode* end){
        
        if(start==head){
            ListNode* check = head;
            while(check->next != end) {
                check = check -> next ;
            }
            
            end -> next = head -> next;
            check -> next = start;
            start -> next = 0;
            return head = end;
            
        }
        
        else if(start->next->next==0){
            ListNode* p = start;
            end->next = start;
            start ->next = 0;
            return head=start;
        }
        else if(start->next == end){
            
            ListNode* tmp = start;
            ListNode* tmp1 = end;

            ListNode* check = head;
            while(check->next!=start) {
                check = check -> next;
            }
            
            ListNode* p = tmp -> next;
            ListNode* q = tmp1 -> next;
            
            check -> next = tmp1;
            tmp1->next = start;
            start -> next = q;
            
            return head;
        }
        
        else{
            ListNode* tmp = start;
            ListNode* tmp1 = end;

            ListNode* check = head;
            while(check->next!=start) {
                check = check -> next;
            }
            
            ListNode* check1 = head;
            while(check1->next != end) {
                check1 = check1 -> next;
            }
            
            
            ListNode* p = tmp -> next;
            ListNode* q = tmp1 -> next;
            
            check -> next = tmp1;
            tmp1 -> next = p;
            
            check1 -> next = tmp;
            tmp -> next = q;
            
            return head;
        }
        
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next == 0){
            return head;
        }
        
        ListNode* curr = head;
        ListNode* tmp = head;
        ListNode* tmp1 = head;
        int cnt=0;
        //Taking Length of List
        while(curr!=0) {
            curr = curr -> next;
            cnt++;
        }
        
        
        //K'th node form end of list
        int p = cnt-k;
        ListNode* tail = head;
        while(--p) {
            tail = tail -> next;
        }
        tmp1 = tail->next;
        
        
        //When Node is One Only
        if(k==1) {
            return swap(head, head,tmp1);
        }
        
        //K'th node form beginning of list
        while(--k){
            tmp = tmp -> next;
        }
        
        return swap(head,tmp, tmp1);
        
    }
};