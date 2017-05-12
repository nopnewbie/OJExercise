#define DEBUG
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x = 0) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution {

    void convertNode(TreeNode *pRoot, TreeNode* &pLastNodeInList)
    {
        if (!pRoot) return;

        TreeNode *pCur = pRoot;
        if (pCur->left)
            convertNode(pCur->left, pLastNodeInList);
        pCur->left = pLastNodeInList;
        if (pLastNodeInList != nullptr)
            pLastNodeInList->right = pCur;
        pLastNodeInList = pCur;

        if (pCur->right)
            convertNode(pCur->right, pLastNodeInList);
    }

public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree)
            return nullptr;

        TreeNode *pLastNodeInList = nullptr;
        convertNode(pRootOfTree, pLastNodeInList);
        while (pLastNodeInList && pLastNodeInList->left)
            pLastNodeInList = pLastNodeInList->left;
        return pLastNodeInList;
    }
};


TreeNode *buildBST(TreeNode *tree)
{
    tree[1].left = tree;
    tree[1].right = tree + 2;

    tree[3].left = tree + 1;
    tree[3].right = tree + 4;
    return tree + 3;
}

void printBST(TreeNode *pRoot)
{
    if (!pRoot)
        return;
    printBST(pRoot->left);
    printf("%d\n", pRoot->val);
    printBST(pRoot->right);
}

void printList(TreeNode *pHead)
{
    while (pHead)
    {
        printf("%d ", pHead->val);
        pHead = pHead->right;
    }
    puts("");
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    TreeNode tree[5];
    for (int i = 0; i < 5; ++i)
        tree[i].val = i;
    buildBST(tree);
    printBST(tree + 3);

    Solution s;
    auto pHead = s.Convert(tree + 3);
    printList(pHead);
    return 0;
}

/*
    BST的中序遍历即为元素的升序。
    所以调整为有序双向链表的顺序与BST的中序遍历顺序是一致的，故可以在遍历的时候实现之。
    在遍历完一棵子树后，该子树被调整为一个有序的双向链表。
    具体做法：
        1. pRoot->left=左子树的最右节点(即左子树的最大节点), 也是当前有序链表的最后一个节点
        2. pRoot->right=右子树的最左节点(即右子树的最小节点)
    ps: 关键在于得到当前有序链表的最后一个节点。
        为此，上述代码中用了一个pLastNodeInList来记录的当前有序链表的最后一个节点。
*/