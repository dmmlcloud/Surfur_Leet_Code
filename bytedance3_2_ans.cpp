#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result;
        ListNode *node = new ListNode(0);
        result = node;
        int i = 0;
        vector<int> carry;
        carry.push_back(0);
        while(l1 != NULL && l2 != NULL){
            int count = carry[i] + l1->val + l2->val;
            node->val = count % 10;
            if(l1->next == NULL || l2->next == NULL)
                node->next = NULL;
            else{
                node->next = new ListNode(0);
                node = node->next;
            }
            l1 = l1->next;
            l2 = l2->next;
            count = count / 10;
            carry.push_back(count % 10);
            i++;
        }
        while(l1 != NULL){
            node->next = new ListNode(0);
            node = node->next;
            int count = carry[i] + l1->val;
            node->val = count % 10;
            node->next = NULL;
            count = count / 10;
            carry.push_back(count % 10);
            i++;
            l1 = l1->next;
        }
        while(l2 != NULL){
            node->next = new ListNode(0);
            node = node->next;
            int count = carry[i] + l2->val;
            node->val = count % 10;
            node->next = NULL;
            count = count / 10;
            carry.push_back(count % 10);
            i++;
            l2 = l2->next;
        }
        while(i < carry.size()){
            if(carry[i] != 0){
                node->next = new ListNode(0);
                node = node->next;
                node->val = carry[i];
                node->next = NULL;
            }
            i++;
        }
        return result;
    }
};