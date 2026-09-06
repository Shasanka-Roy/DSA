class Solution {
public:

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pq;

        // Put first node of every list into heap
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {

            // Get smallest value
            ListNode* node = pq.top();
            pq.pop();

            // Add node to result
            curr->next = node;
            curr = curr->next;

            // Add next node from same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
