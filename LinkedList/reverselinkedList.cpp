/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Input: head = [5], left = 1, right = 1
Output: [5]
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ppl=nullptr, *prev=nullptr, *curr=head, *n=nullptr;
        int cnt = 0;
        while(cnt <= right) {

            if(cnt < left-1) {
                ppl = curr;
                curr = curr->next;
            }
            else if(cnt == left - 1) {
                prev = curr;
                n = curr->next;
                curr = curr->next;
                prev->next = nullptr;
            }
            else if(cnt > left - 1 && cnt < right) {
                n = curr->next;
                curr->next = prev;
                prev = curr;
                curr = n;
            } 
            else {
                if(ppl != nullptr) {
                    ppl->next->next = n;
                    ppl->next = prev;
                }
                else if(n == nullptr)   head = prev;
                else {
                    head->next = n;
                    head = prev;
                }
            }

            
            cnt++;
        }
        return head;
    }
};
