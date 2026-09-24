class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Find kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            // Node after the group
            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;

                curr->next = prev;

                prev = curr;
                curr = temp;
            }

            // Connect previous part to reversed group
            ListNode* oldGroupStart = groupPrev->next;

            groupPrev->next = prev;

            // Move to next group
            groupPrev = oldGroupStart;
        }
    }
};