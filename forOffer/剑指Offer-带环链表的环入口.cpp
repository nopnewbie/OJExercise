class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		ListNode *pFast = pHead, *pSlow = pHead;
        do 
        {
            if (pFast)
                pFast = pFast->next;
            else 
                return nullptr;
                
            if (pFast)
                pFast = pFast->next;
            else 
                return nullptr;
            pSlow = pSlow->next;
        } while (pFast != pSlow);
        
        while (pHead != pSlow)
        {
            pHead = pHead->next;
            pSlow = pSlow->next;
        }
        return pHead;
    }
};