// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) 
//     {
//         int size = 0;
//         ListNode* curr = head;
//         // ListNode* temp;
//         while(curr != NULL)
//         {
//             size++;
//             curr = curr->next;
//         }
//         int nthNodefromEnd = size - n;

//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;

//         ListNode* prev = dummy;
//         ListNode* temp = head;


//         for (int i = 0; i < nthNodefromEnd; i++)
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = temp->next;
//         delete temp;
//         ListNode* newHead = dummy->next;
//         delete dummy;

//         return newHead;

        
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // move both until fast becomes NULL
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete slow->next
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};