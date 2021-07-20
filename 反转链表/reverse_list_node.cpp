#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) {
        val = val;
        next = nullptr;
    }
};

// 反转链表。 方法一，存入辅助 stack , 方法二新链表接收
class Solution {
    ListNode *reverseListNode(ListNode *pHead) {
        if (!pHead) {
            return nullptr;
        };
        ListNode *pre = nullptr;
        ListNode *cur = pHead;
        ListNode *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() { return 0; }