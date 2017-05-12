/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
   	bool symmetrical(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        return (left->val == right->val)
            && symmetrical(left->left, right->right)
            && symmetrical(left->right, right->left);
    }
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if (!pRoot)
            return true;
        
        return symmetrical(pRoot->left, pRoot->right);
    }

};