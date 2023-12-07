/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a min-heap to store the nodes based on their values
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // Add the head nodes of all linked lists to the min-heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        // Dummy node to simplify code
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Process nodes from the min-heap
        while (!minHeap.empty()) {
            // Get the node with the smallest value
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            // Add the node to the result list
            current->next = minNode;
            current = current->next;

            // Move to the next node in the selected list
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }

        return dummy->next; // Return the merged sorted list
    }
};