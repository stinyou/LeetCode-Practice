
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1->5->7
// 6->7->9

// 1->2
// 0->2

// 1->1->1
// 1->1

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyNode{};
        ListNode* tailNode = &dummyNode;
        while(list1 && list2) {
            if (list1->val <= list2->val) {
                tailNode->next = list1;
                tailNode = tailNode->next;
                list1 = list1->next;
            }
            else { // list1->val > list2->val
                tailNode->next = list2;
                tailNode = tailNode->next;
                list2 = list2->next;
            }
        }
        tailNode->next = list1 ? list1 : list2;
        return dummyNode.next;
    }
};

int main(void) {
    return 0;
}