// this version does not use helper function
class Solution {
public:
    int maxDepth=0;
    TreeNode* subtreeWithAllDeepest(TreeNode* root, int* depth=NULL, int level=0) {
        int d0=0;
        if (!depth) depth=&d0;

        if (!root) {
            *depth=level;
            maxDepth=max(maxDepth, *depth);
            return root;
        }
        int lD=0, rD=0;
        TreeNode* L=subtreeWithAllDeepest(root->left, &lD, level+1);
        TreeNode* R=subtreeWithAllDeepest(root->right, &rD, level+1);

        *depth=max(lD, rD);
        if (lD==rD && lD==maxDepth) return root;
        return (lD>rD)?L:R;
    }
};