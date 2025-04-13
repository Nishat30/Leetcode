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
        ListNode* ans=NULL;
        queue<int> q;
        int carry = 0;
        while(l1!=NULL || l2!=NULL ||carry!=0){
            int sum=0;
            if(l1!=NULL){sum+=l1->val;}
            if(l2!=NULL){sum+=l2->val;}
            sum+=carry;
            int digit=sum%10;
            carry=sum/10;
            q.push(digit);
            if(l1!=NULL){l1=l1->next;}
            if(l2!=NULL){l2=l2->next;}
        }
        ListNode* temp=NULL;
        while(!q.empty()){
            ListNode* newNode= new ListNode(q.front());
            q.pop();
            if(ans==NULL){
                ans=newNode;
                temp=ans;
            }else{
                temp->next=newNode;
                temp=newNode;
            }
        }
        return ans;
    }
};