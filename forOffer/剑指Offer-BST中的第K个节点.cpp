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
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (!pRoot)
            return nullptr;
        
        stack<TreeNode*> stk;
        TreeNode *p = pRoot;
        int cnt = 0;
        while (p || !stk.empty()) 
        {
            if (p)
            {
                stk.push(p);
                p = p->left;
            }
            else 
            {
                p = stk.top(); 
                stk.pop();
                if (++cnt == k)
                    return p;
                p = p->right;
            }
        }
        return nullptr;
        
    }
    
};

/*
	BST的中序遍历是有序的，故可以用非递归的中序遍历高效的实现之。
*/