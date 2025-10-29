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
    int len(ListNode* head){
        int i=0;
        while(head!=NULL){
            i++;
            head=head->next;
        }
        return i;
    }
    ListNode* middleNode(ListNode* head) {
        int length=len(head);
        int mid=length/2;
        int i=0;
        while(i!=mid){
            head=head->next;
            i++;
        }
        return head;
    }
};