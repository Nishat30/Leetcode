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
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next;  
            curr->next = prev;       
            prev = curr;             
            curr = nextNode;         
        }
        return prev; 
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverseList(slow->next);
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;
        bool isPalin = true;

        while (temp != nullptr) {
            if (firstHalf->val != temp->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        return isPalin;
    }
};
