#include<iostream>
#include<unordered_map>
using namespace std;
//复杂链表的深拷贝
struct ListNode
{
public :
	int val;
	struct ListNode *next, *rand;
    ListNode(int x):
        val(x), next(NULL), rand(NULL){
    }
};
class Solution {
public:
    ListNode* copyListWithRand1(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode* cur = head;
		ListNode* next = NULL;
		// copy node and link to every node
		// 1 -> 2
		// 1 -> 1' -> 2
		while (cur != NULL) {
			next = cur->next;
			cur->next = new ListNode(cur->val);
			cur->next->next = next;
			cur = next;
		}
		cur = head;
		ListNode* curCopy = NULL;
		// set copy node rand
		// 1 -> 1' -> 2 -> 2'
		while (cur != NULL) {
			next = cur->next->next;
			curCopy = cur->next;
			curCopy->rand = cur->rand != NULL ? cur->rand->next : NULL;
			cur = next;
		}
		ListNode* res = head->next;
		cur = head;
		// split
		while (cur != NULL) {
			next = cur->next->next;
			curCopy = cur->next;
			cur->next = next;
			curCopy->next = next != NULL ? next->next : NULL;
			cur = next;
		}
		return res;
	}
    ListNode* copyListWithRand2(ListNode* head) {
        unordered_map<ListNode*,ListNode*>hashmap;
		ListNode* cur = head;
		while (cur != NULL) {
			hashmap[cur] = new ListNode(cur->val);
			cur = cur->next;
		}
		cur = head;
		while (cur != NULL) {
			// cur 老
			// map.get(cur) 新
			hashmap[cur]->next = hashmap[cur->next];
			hashmap[cur]->rand = hashmap[cur->rand];
			cur = cur->next;
		}
		return hashmap[head];
	}
};