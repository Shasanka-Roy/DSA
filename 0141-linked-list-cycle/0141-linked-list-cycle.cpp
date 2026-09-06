class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // moves 1 step
            fast = fast->next->next;     // moves 2 steps

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
