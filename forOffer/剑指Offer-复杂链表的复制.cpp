#define DEBUG
#include <iostream>
#include <algorithm>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

class Solution {
    void copySelf(RandomListNode *pHead)
    {
        while (pHead)
        {
            RandomListNode *newNode = new RandomListNode(pHead->label);
            RandomListNode *next = pHead->next;
            pHead->next = newNode;
            newNode->next = next;
            pHead = next;
        }
    }

    void adjustRandomPointer(RandomListNode *pHead)
    {
        while (pHead)
        {
            RandomListNode* next = pHead->next;
            if (pHead->random)
                next->random = pHead->random->next;
            pHead = next->next;
        }
    }

    RandomListNode *splitList(RandomListNode *pHead)
    {
        RandomListNode newHead(0);
        RandomListNode *p = &newHead, *q = nullptr;
        while (pHead)
        {
            q = pHead->next;
            p->next = q;
            p = q;
            pHead->next = q->next;
            pHead = pHead->next;
        }
        return newHead.next;
    }

public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        copySelf(pHead);
        adjustRandomPointer(pHead);
        return splitList(pHead);
    }
};

RandomListNode *generateList(int length)
{
    RandomListNode head(0), *p = &head, *q;
    while (length--)
    {
        q = new RandomListNode(length);
        p->next = q;
        p = q;
    }
    return head.next;
}

void printList(RandomListNode *pHead)
{
    while (pHead)
    {
        printf("val: %d, next: %08x, random: %08x\n", pHead->label, pHead->next, pHead->random);
        pHead = pHead->next;
    }
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    RandomListNode *pHead = generateList(5);
    printList(pHead);
    Solution s;
    RandomListNode *newHead = s.Clone(pHead);
    printList(newHead);
    return 0;
}