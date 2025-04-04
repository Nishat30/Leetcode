/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val|| root->val==q->val){
            return root;
        }
        auto l=lowestCommonAncestor(root->left,p,q);
        auto r=lowestCommonAncestor(root->right,p,q);

        if(l!=NULL && r!=NULL){
            return root;
        }
        else if(l!=NULL && r==NULL){
            return l;
        }else if(l==NULL && r!=NULL){
            return r;
        }
        return NULL;
    }
};