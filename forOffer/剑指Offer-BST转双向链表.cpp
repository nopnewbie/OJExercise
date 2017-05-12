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
    BST�����������ΪԪ�ص�����
    ���Ե���Ϊ����˫�������˳����BST���������˳����һ�µģ��ʿ����ڱ�����ʱ��ʵ��֮��
    �ڱ�����һ�������󣬸�����������Ϊһ�������˫������
    ����������
        1. pRoot->left=�����������ҽڵ�(�������������ڵ�), Ҳ�ǵ�ǰ������������һ���ڵ�
        2. pRoot->right=������������ڵ�(������������С�ڵ�)
    ps: �ؼ����ڵõ���ǰ������������һ���ڵ㡣
        Ϊ�ˣ���������������һ��pLastNodeInList����¼�ĵ�ǰ������������һ���ڵ㡣
*/