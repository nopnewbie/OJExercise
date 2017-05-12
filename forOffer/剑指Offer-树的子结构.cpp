/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    bool DoesHaveSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot2)
            return true;
        if (!pRoot1)
            return false;
        if (pRoot1->val == pRoot2->val)
            return DoesHaveSubTree(pRoot1->left, pRoot2->left) &&
            	   DoesHaveSubTree(pRoot1->right, pRoot2->right);
        else 
            return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool result = false;
        if (pRoot1 && pRoot2)
        {
            if (pRoot1->val == pRoot2->val)
                result = DoesHaveSubTree(pRoot1, pRoot2);
            if (!result)
                result =  HasSubtree(pRoot1->left, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
};