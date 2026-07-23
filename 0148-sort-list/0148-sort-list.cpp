class Solution {
public:

    ListNode* merge(ListNode* right, ListNode* left) {

        ListNode dummy;
        ListNode* temp = &dummy;

        while (left && right) {

            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if (left) {
            temp->next = left;
        }
        else {
            temp->next = right;
        }

        return dummy.next;
    }


    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;             // FIX 1
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = nullptr;        // FIX 2
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};