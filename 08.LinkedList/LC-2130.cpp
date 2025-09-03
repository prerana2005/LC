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
    int pairSum(ListNode* head) {
        // Step 1: Find middle using slow/fast pointer
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Step 3: Calculate twin sums
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev; // reversed second half
        while (second) {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};
