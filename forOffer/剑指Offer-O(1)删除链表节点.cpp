/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        auto next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};

/*
	本题有一个前提条件——待删结点的位于所给链表中。面试时可以先向面试官确认这一点。
*/