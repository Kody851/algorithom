#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next, *rand;
    ListNode(int x):
        val(x), next(NULL), rand(NULL){}
};

ListNode *copylist(ListNode* head){
    if(head == NULL) return NULL;
    //1->2   =>    1->1'->2->2'
    ListNode *cur = head, *tmp = NULL;
    while(cur){
        tmp = cur->next;
        cur->next = new ListNode(cur->val);
        cur->next->next = tmp;
        cur = tmp;
    }
    //rand
    cur = head;
    while(cur){
        cur->next->rand = cur->rand ? cur->rand->next : NULL;
        cur = cur->next->next;
    }
    //1->1'->2->2' => 1->2 ,  1'->2'.   return 1'->2'
    cur = head;
    ListNode*res = head->next;
    while(cur){
        tmp = cur->next->next;
        cur->next->next = tmp ? tmp->next : NULL;
        cur->next = tmp;
        cur = tmp;
    }    
    return res;


}