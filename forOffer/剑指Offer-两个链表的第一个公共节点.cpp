/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
    int length(ListNode *pHead)
    {
        int len = 0;
        while (pHead)
        {
            ++len;
            pHead = pHead->next;
        }
        return len;
    }
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
     	int len1 = length(pHead1), len2 = length(pHead2);
       	while (len1 > len2)
        {
            --len1;
             pHead1 = pHead1->next;
        }
        while (len2 > len1)
        {
            --len2;
            pHead2 = pHead2->next;
        }
        while (pHead1 != pHead2)
        {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};