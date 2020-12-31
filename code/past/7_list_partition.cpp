#include<iostream>
#include<vector>
using namespace std;
/*
给定一个单链表的头节点head， 节点的值类型是整型， 再给定一个整
数pivot。 实现一个调整链表的函数， 将链表调整为左部分都是值小于pivot的
节点， 中间部分都是值等于pivot的节点， 右部分都是值大于pivot的节点。
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
    void swap(vector<ListNode*> &arr, int i, int j) {
            ListNode* tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
    }
    void arrPartition(vector<ListNode*> &nodeArr, int pivot) {
		int small = -1;
		int big = nodeArr.size();
		int index = 0;
		while (index != big) {
			if (nodeArr[index]->val < pivot) {
				swap(nodeArr, ++small, index++);
			} else if (nodeArr[index]->val == pivot) {
				index++;
			} else {
				swap(nodeArr, --big, index);
			}
		}
	}
    //用排序中的partition函数做
    ListNode* listPartition1(ListNode* head, int pivot) {
		if (head == NULL) {
			return head;
		}
		ListNode* cur = head;
		int i = 0;
		while (cur != NULL) {
			i++;
			cur = cur->next;
		}
		vector<ListNode*>nodeArr(i);
		i = 0;
		cur = head;
		for (i = 0; i != nodeArr.size(); i++) {
			nodeArr[i] = cur;
			cur = cur->next;
		}
		arrPartition(nodeArr, pivot);
		for (i = 1; i != nodeArr.size(); i++) {
			nodeArr[i - 1]->next = nodeArr[i];
		}
		nodeArr[i - 1]->next = NULL;
		return nodeArr[0];
	}

	//建立3段链表；复杂度相同，区别是不用vector容器
    ListNode* listPartition2(ListNode* head, int pivot) {
		ListNode* sH = NULL; // small head
		ListNode* sT = NULL; // small tail
		ListNode* eH = NULL; // equal head
		ListNode* eT = NULL; // equal tail
		ListNode* mH = NULL; // big head
		ListNode* mT = NULL; // big tail
		ListNode* next = NULL; // save next node
		// every node distributed to three lists
		while (head != NULL) {
			next = head->next;
			head->next = NULL;
			if (head->val < pivot) {
				if (sH == NULL) {
					sH = head;
					sT = head;
				} else {
					sT->next = head;
					sT = head;
				}
			} else if (head->val == pivot) {
				if (eH == NULL) {
					eH = head;
					eT = head;
				} else {
					eT->next = head;
					eT = head;
				}
			} else {
				if (mH == NULL) {
					mH = head;
					mT = head;
				} else {
					mT->next = head;
					mT = head;
				}
			}
			head = next;
		}
		// small and equal reconnect
		if (sT != NULL) { // 如果有小于区域
			sT->next = eH;
			eT = eT == NULL ? sT : eT; // 下一步，谁去连大于区域的头，谁就变成eT
		}
		// 上面的if，不管跑了没有，et
		// all reconnect
		if (eT != NULL) { // 如果小于区域和等于区域，不是都没有
			eT->next = mH;
		}
		return sH != NULL ? sH : (eH != NULL ? eH : mH);
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
    //输入
    ListNode* list = new ListNode(1);
    list->next=new ListNode(4);
    list->next->next=new ListNode(5);
    list->next->next->next=new ListNode(2);
    list->next->next->next->next=new ListNode(4);
    list->next->next->next->next->next=new ListNode(6);
    cout<<"OriginalList: ";
    printListNode(list);

    Solution solu;
    ListNode *list_res = solu.listPartition1(list, 4);
    //打印partition结果
    cout<<"partition(pivot=4): ";
    printListNode(list_res);
    
    
    return 0;
}