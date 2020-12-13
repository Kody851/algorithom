#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x), next(NULL){}
};

ListNode* FirstNodeCircle(ListNode*head){
    if(head==NULL || head->next==NULL || head->next->next==NULL) return NULL;

    ListNode *p1 = head->next, *p2 = head->next->next;
    while(p1 != p2){
        if(p2->next==NULL || p2->next->next==NULL) return NULL;
        p1 = p1->next;
        p2 = p2->next->next;
    }

    int numOfNodeInCircle = 1;
    ListNode*cur = p1->next;
    while(cur!=p1){
        numOfNodeInCircle++;
        cur = cur->next;
    }

    p1=head, p2=head;
    for(int i=0; i<numOfNodeInCircle; i++){
        p1 = p1->next;
    }
    while(p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

ListNode* noLoop(ListNode*head1, ListNode*head2){
    if(!head1 || !head2){
        return NULL;
    }
    int n=0;
    ListNode*cur1 = head1;
    while(cur1){
        n++;
        cur1 = cur1->next;
    }
    ListNode*cur2 = head2;
    while(cur2){
        n--;
        cur2 = cur2->next;
    }
    cur1 = n>0 ? head1 : head2;//long
    cur2 = n>0 ? head2 : head1;//short
    n = n>0 ? n : -n;
    for(int i=0;i<n;i++){
        cur1 = cur1->next;
    }
    while(cur1!=cur2){
        if(cur1->next==NULL || cur2->next==NULL){
            return NULL;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;

}