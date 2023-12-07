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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        // Move to the starting point
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }

        // Reverse the sublist from left to right
        ListNode* current = pre->next;
        ListNode* next_node = nullptr;
        ListNode* prev = nullptr;

        for (int i = 0; i <= right - left; ++i) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        // Connect the reversed sublist back to the main list
        pre->next->next = current;
        pre->next = prev;

        return dummy->next;
    }
};