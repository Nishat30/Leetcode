/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //step 1: insert copy nodes in between
        Node* temp=head;
        while(temp!=NULL){
            Node* nextNode=temp->next;
            Node* copyNode=new Node(temp->val);
            copyNode->next=nextNode;
            temp->next=copyNode;
            temp=nextNode;
        }
        //step 2: connect the random pointers
        temp=head;
        while(temp!=NULL){
            if(temp->random)
                temp->next->random=temp->random->next; 
            temp=temp->next->next;
        }
        //step 3: connect next pointer
        temp = head;
        Node* dummyNode = new Node(-1);   
        Node* res = dummyNode;  
        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }
};