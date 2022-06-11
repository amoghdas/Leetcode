#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *left = nullptr;
    ListNode *middle = nullptr;
    ListNode *right = nullptr;
    if (head) {
        left = head;
    } else { 
        return head;
    } 
    
    if (left->next) {
        middle = left->next;
    } else {
        return left;
    }
    
    if (middle->next) {
        right = middle->next;
    } else {
        middle->next = head;
        left->next = nullptr;
        return middle;
    }
    
    // Main iterative logic
    while (right) {
        middle->next = left;
        if (left == head) left->next = nullptr;
        left = middle;
        middle = right;
        if (right->next == nullptr) {
            right->next = left;
            return right;
        }
        right = right->next;
    }
    return nullptr; // This will never be executed
}

void printll(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        std::cout << cur->val << ' ';
        cur = cur->next;
    }
    std::cout << '\n';
}

int main() {
    ListNode *head = new ListNode(5);
    ListNode *cur = head;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);
    cur = cur->next;

    printll(head);
    ListNode *new_head = reverseList(head);
    printll(new_head);
}