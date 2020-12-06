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
		ListNode* tmp = NULL;
		// copy node and link to every node
		//1->2   =>    1->1'->2->2'
		while (cur) {
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


	//hash表法
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