//
//  main.cpp
//  AddTwoNumbers_p2
//
//  Created by 魏思哲 on 26/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//
//1. 要考虑到两个0的问题；
//2. 用int型加法要考虑到长整型溢出的问题；（必须改用链表了）
//3. 改用链表之后，要注意两个链表不等长的问题；
#include <iostream>
#include <math.h>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p;
        int num1=0,num2=0,i=0;
        p = l1;
        while(p!=NULL){
            num1 = num1 + pow(10,i)*p->val;
            p = p->next;
            i++;
        }
        
        p = l2;
        i = 0;
        while(p!=NULL){
            num2 = num2 + pow(10,i)*p->val;
            p = p->next;
            i++;
        }
        
        cout<<num1<<","<<num2<<endl;
        int nums = num1 + num2; int tmp=0;
        ListNode *result = new ListNode(0), *head, *pre, *tmpnode;
        pre = result;
        head = result;
        if(nums==0) return result;
        
        while(nums!=0){
            tmp = nums%10;
            nums /= 10;
            tmpnode = new ListNode(tmp);
            pre->next = tmpnode;
            pre = pre->next;
        }
        
        return result->next;
    }
};
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result=new ListNode(0);
        ListNode *p1, *p2, *head, *pre, *tmp;
        p1 = l1; p2 = l2; head = result; pre = head;
        bool carry=false;
        int num=0;
        while(p1!=NULL||p2!=NULL||carry==true){
            if(p1!=NULL&&p2!=NULL){
                if(carry){
                    num = p1->val + p2->val + 1;
                }
                else{
                    num = p1->val + p2->val;
                }
            }
            else if (p1!=NULL&&carry){
                num = p1->val + 1;
            }
            else if (p2!=NULL&&carry){
                num = p2->val + 1;
            }
            else if (p1!=NULL||p2!=NULL){
                if(p1!=NULL){
                    pre->next = p1;
                }
                else{
                    pre->next = p2;
                }
                return result->next;
            }
            else{
                carry = false;
                tmp = new ListNode(1);
                pre->next = tmp;
                pre = tmp;
                return result->next;
            }
            if(num>=10){
                num -= 10;
                carry = true;
            }
            else carry = false;
            tmp = new ListNode(num);
            pre->next = tmp;
            pre = tmp;
            if(p1!=NULL) p1 = p1->next;
            if(p2!=NULL) p2 = p2->next;
        }
        return result->next;
    }
};

int main() {
    ListNode a1(9),b1(1),*head1,*head2,*tmp,*pre2;
    head1 = &a1;
    
    head2 = &b1;
    pre2 = head2;
    for(int i=0;i<9;i++){
        tmp = new ListNode(9);
        pre2->next = tmp;
        pre2 = tmp;
    }
        
    Solution problem;
    ListNode *result = problem.addTwoNumbers(head1, head2);
    ListNode *p = result;

    while(p!=NULL){
        cout<<p->val<<",";
        p = p->next;
    }

    return 0;
}
