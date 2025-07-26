/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]

*/




 #include <bits/stdc++.h>
 using namespace std;

/*
 * Definition for singly-linked list.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ls = nullptr, *le = nullptr, *rs = nullptr, *re = nullptr, *curr=head;

        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        while(curr != nullptr)  {
            if(curr->val < x && ls==nullptr) {
                ls = curr;
                le = curr;
            }
            else if(curr->val < x)  {
                le->next = curr;
                le = curr;
            }
            else if(curr->val >= x && rs==nullptr) {
                rs = curr;
                re = curr;
            }
            else if(curr->val >= x)  {
                re->next = curr;
                re = curr;
            }
            curr = curr->next;
        }
        if(le!=nullptr)
            le->next = rs;
        if(re!=nullptr)
            re->next = nullptr;
        if(le == nullptr)   return rs;
        return ls;
        
    }
};