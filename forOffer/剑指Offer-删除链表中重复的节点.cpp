class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode head(0);
        head.next = pHead;
		ListNode *pCur = pHead, *pNext, *pPrev = &head;
        while (pCur)
        {
            bool flag = false;
            pNext = pCur->next;
            while (pNext && pNext->val == pCur->val)
            {
                flag = true;
                ListNode *pDelete = pNext;
                pCur->next = pNext->next;
                pNext = pCur->next;
                delete pDelete;
            }
            if (flag)
            {
                pPrev->next = pNext;
                delete pCur;
            }
            else 
            {
                pPrev = pCur;
            }
            pCur = pNext;
        }
        return head.next;
    }
};