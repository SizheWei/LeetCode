//
//  main.cpp
//  MergeTwoSortedLists
//
//  Created by 魏思哲 on 6/12/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//

#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1,*p2;
        p1 = l1;
        p2 = l2;

        ListNode tmp(0), *result, *presult;
        result = &tmp;
        presult = result;

//        int test_i = 0;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val <= p2->val) {
                presult->next = p1;
                p1 = p1->next;
            }
            else {
                presult->next = p2;
                p2 = p2->next;
            }
            
            presult = presult->next;
            presult->next = NULL;

//            test_i++;
//            cout<<"round: "<<test_i<<endl;
        }

        if (p1 == NULL) {
            presult->next = p2;
        }
        else presult->next = p1;

        result = tmp.next;

        return result;
    }
};

int main() {
    ListNode a1(2),b1(3),c1(6),d1(9),*head1,*p1;
    head1 = &a1;
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    p1 = head1;

//    ListNode a2(0),b2(3),c2(8),*head2,*p2;
    ListNode a2(0),*head2,*p2;
    head2 = &a2;
//    a2.next = &b2;
//    b2.next = &c2;
    p2 = head2;
    
//    ListNode * result, *presult, tmp(0);
//    result = &tmp;
//    presult = result;
//    presult->next = p1;
//    p1 = p1->next;
//    presult = presult->next;
//    presult->next = NULL;
//
//    while(result != NULL){
//        cout<<result->val<<endl;
//        result = result->next;
//    }
    
    Solution problem;
    ListNode * p;
    p = problem.mergeTwoLists(head1, head2);

    while(p != NULL){
        cout<<p->val<<endl;
        p = p->next;
    }
    
    return 0;
}
