#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void traverseList(Node* head) {
    while(head->next != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }
}


int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(30);

    traverseList(head);

    return 0;
}