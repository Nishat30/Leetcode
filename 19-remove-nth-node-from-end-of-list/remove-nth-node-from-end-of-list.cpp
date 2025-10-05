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
    int lengthOfNode(ListNode *head){
        int i=0;
        while(head!=NULL){
            head=head->next;
            i++;
        }
        return i;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=lengthOfNode(head);
        if (n == length) {
            ListNode* newHead = head->next;
            delete head; // Free the memory of the removed node
            return newHead;
        }
        ListNode *temp=head;
        int cnt=0;
        while(cnt<length-n-1){
            temp=temp->next;
            cnt++;
        }
        ListNode* toRemove=temp->next;
        temp->next=toRemove->next;
        delete toRemove;
        return head;
    }
};