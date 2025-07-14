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
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        reverse(arr.begin(),arr.end());
        ListNode* newHead = NULL;
        ListNode* tail = NULL;

        for (int i = 0; i < arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            if (newHead == NULL) {
                newHead = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return newHead;
    }
};