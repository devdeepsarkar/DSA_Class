/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:

Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head, *p=nullptr, *n=nullptr;
        ListNode *newhead;
        if(head == nullptr)    return head;
        else if(head->next == nullptr)  return head;
        else {
            newhead = head->next;
            while(curr != nullptr) {
                n = curr->next;
                p = n->next;
                if(p != nullptr) {
                    if(p->next != nullptr) {
                        curr->next = p->next;
                        n->next = curr;
                    }
                    else {
                        curr->next = p;
                        n->next = curr;
                        p = nullptr;
                    }
                   
                }
                else {
                    curr->next = nullptr;
                    n->next = curr;
                }
                curr = p;
            }
        }
        return newhead;
        
    }
};