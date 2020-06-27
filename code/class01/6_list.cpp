#include<iostream>
#include<stack>
using namespace std;

//IsPalindromeList
/*struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
struct ListNode
{
public :
	int val;
	struct ListNode *next;

};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return NULL;
        ListNode *cur=pHead;
        ListNode *pre=NULL;
        ListNode *tmp=NULL;
        while(cur){
            tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
public:
    // need n extra space
    bool isPalindrome1(ListNode* head){
        stack<ListNode*>stk;
        ListNode* cur=head;
        while(cur){
            stk.push(cur);
            cur=cur->next;
        }
        cur=head;
        while(cur){
            if(cur->val==stk.top()->val){
                stk.pop();
                cur=cur->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    //need O(1) extra space
    bool isPalindrome(ListNode* head){
    if (head == NULL || head->next == NULL) {
			return true;
		}
		ListNode* n1 = head;
		ListNode* n2 = head;
		while (n2->next != NULL && n2->next->next != NULL) { // find mid node
			n1 = n1->next; // n1 -> mid
			n2 = n2->next->next; // n2 -> end
		}
		n2 = n1.next; // n2 -> right part first node
		n1.next = null; // mid.next -> null
		Node n3 = null;
		while (n2 != null) { // right part convert
			n3 = n2.next; // n3 -> save next node
			n2.next = n1; // next of right node convert
			n1 = n2; // n1 move
			n2 = n3; // n2 move
		}
		n3 = n1; // n3 -> save last node
		n2 = head;// n2 -> left first node
		boolean res = true;
		while (n1 != null && n2 != null) { // check palindrome
			if (n1.value != n2.value) {
				res = false;
				break;
			}
			n1 = n1.next; // left to mid
			n2 = n2.next; // right to mid
		}
		n1 = n3.next;
		n3.next = null;
		while (n1 != null) { // recover list
			n2 = n1.next;
			n1.next = n3;
			n3 = n1;
			n1 = n2;
		}
		return res;
    }
};


int main(){
    //输入
	ListNode list[5];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = &list[4];
    list[4].val = 5;
    list[4].next = NULL;
	ListNode *node = list;
    cout<<"OriginalList: ";
    while(node != NULL)
    {
        cout <<node->val<<"->";
        node = node->next;
    }
    cout <<"NULL"<<endl;

    Solution solu;
	//链表反转
    /*
	node = solu.ReverseList(list);
	cout<<"ReverseList: ";
    while(node != NULL)
    {
        cout <<node->val<<"->";
        node = node->next;
    }
    cout <<"NULL"<<endl;
    */
    //判断是否回文
    cout<<"isPalindrome"<<solu.isPalindrome1(list);
    return 0;
}
