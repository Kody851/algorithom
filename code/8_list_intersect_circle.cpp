#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*===链表集大成====
给定两个可能有环也可能无环的单链表， 头节点head1和head2。 请实
现一个函数， 如果两个链表相交， 请返回相交的 第一个节点。 如果不相交， 返
回NULL。
【 要求】 如果两个链表长度之和为N， 时间复杂度请达到O(N)， 额外空间复杂度
请达到O(1)。
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution{
public:
    //两个链表(有无环未知)第一个公共(相交的)节点
    ListNode* getIntersectNode(ListNode* head1, ListNode* head2) {
		if (head1 == NULL || head2 == NULL) {
			return NULL;
		}
		ListNode* loop1 = getLoopNode(head1);
		ListNode* loop2 = getLoopNode(head2);
		if (loop1 == NULL && loop2 == NULL) {
			return noLoop(head1, head2);
		}
		if (loop1 != NULL && loop2 != NULL) {
			return bothLoop(head1, loop1, head2, loop2);
		}
		return NULL;
	}

	// 找到链表第一个入环节点，如果无环，返回null
	ListNode* getLoopNode(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL) {
			return NULL;
		}
		ListNode* n1 = head->next; // n1 -> slow
		ListNode* n2 = head->next->next; // n2 -> fast
		while (n1 != n2) {
			if (n2->next == NULL || n2->next->next == NULL) {
				return NULL;
			}
			n2 = n2->next->next;
			n1 = n1->next;
		}
		//法1，简单，但是难理解
		/*
		n2 = head; // n2 -> walk again from head
		while (n1 != n2) {
			n1 = n1->next;
			n2 = n2->next;
		}
		return n1;
		*/
		//法2
		//计算环内结点数
        int NumOfCurcle=1;
        ListNode*cur=n1->next;
        while(cur!=n1){
            NumOfCurcle++;
            cur=cur->next;
        }
        //定位环的入口结点
        n1=head;
        n2=head;
        for(int i=0;i<NumOfCurcle;i++) n1=n1->next;
        while(n1!=n2){
            n1=n1->next;
            n2=n2->next;
        }
        return n1;
	}

	// 如果两个链表都无环，返回第一个相交节点，如果不想交，返回null
	ListNode* noLoop(ListNode* head1, ListNode* head2) {
		if (head1 == NULL || head2 == NULL) {
			return NULL;
		}
		ListNode* cur1 = head1;
		ListNode* cur2 = head2;
		int n = 0;
		while (cur1->next != NULL) {
			n++;
			cur1 = cur1->next;
		}
		while (cur2->next != NULL) {
			n--;
			cur2 = cur2->next;
		}
		if (cur1 != cur2) {//若有公共部分，则最后一个节点必相同。（Y字形）
			return NULL;
		}
		// n  :  链表1长度减去链表2长度的值
		cur1 = n > 0 ? head1 : head2; // 谁长，谁的头变成cur1
		cur2 = cur1 == head1 ? head2 : head1; // 谁短，谁的头变成cur2
		n = n>=0 ? n : -n;
		while (n != 0) {
			n--;
			cur1 = cur1->next;
		}
		while (cur1 != cur2) {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {//noLoop的hasn版本
          if(pHead1==NULL||pHead2==NULL) return NULL;
          unordered_set<ListNode*> hashset;
          ListNode *pNode1=pHead1,*pNode2=pHead2;
          //把链表2转存为哈希表
          while(pNode2!=NULL){
              hashset.insert(pNode2);
              pNode2=pNode2->next;
          }
          //遍历第一个链表
          while(pNode1!=NULL){
            if(hashset.find(pNode1)!=hashset.end()){
                return pNode1;
            }
            pNode1=pNode1->next;
          }
          return NULL;
    }

	// 两个有环链表，返回第一个相交节点，如果不想交返回null
	ListNode* bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2) {
		ListNode* cur1 = NULL;
		ListNode* cur2 = NULL;
		if (loop1 == loop2) {//入环节点相同（Y+O）
			cur1 = head1;
			cur2 = head2;
			int n = 0;
			while (cur1 != loop1) {//把入环节点当做Y的尾节点，用noLoop方法
				n++;
				cur1 = cur1->next;
			}
			while (cur2 != loop2) {
				n--;
				cur2 = cur2->next;
			}
			cur1 = n > 0 ? head1 : head2;
			cur2 = cur1 == head1 ? head2 : head1;
			n = n>=0 ? n : -n;
			while (n != 0) {
				n--;
				cur1 = cur1->next;
			}
			while (cur1 != cur2) {
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		} 
		else {//入环节点不同（-O-）
			cur1 = loop1->next;
			while (cur1 != loop1) {
				if (cur1 == loop2) {
					return loop1;//loop1与loop2两个答案都可以
				}
				cur1 = cur1->next;
			}
			return NULL;//-O -O不相交
		}
	}

};
void printListNode(ListNode*list){
    ListNode *node = list;
    while(node != NULL)
    {
        cout <<node->val<<"->";
        node = node->next;
    }
    cout <<"NULL"<<endl;
}
int main(){
    // 1->2->3->4->5->6->7->null
    ListNode* head1 = new ListNode(1);
    head1->next=new ListNode(2);
    head1->next->next=new ListNode(3);
    head1->next->next->next=new ListNode(4);
    head1->next->next->next->next=new ListNode(5);
    head1->next->next->next->next->next=new ListNode(6);
    head1->next->next->next->next->next->next=new ListNode(7);
    // 0->9->8->6->7->null
    ListNode* head2 = new ListNode(0);
    head2->next=new ListNode(9);
    head2->next->next=new ListNode(8);
    head2->next->next->next=head1->next->next->next->next->next;// 8->6

    Solution solu;
    cout<<"IntersectNode: ";
    cout<<solu.getIntersectNode(head1, head2)->val;
    
    
    return 0;
}