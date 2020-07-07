#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution{
public:
    //递归，先序
    void preOrderRecur(TreeNode* head) {
		if (head == NULL) {
			return;
		}
		cout<< head->val << " ";
		preOrderRecur(head->left); 
		preOrderRecur(head->right);
	}
    //递归，中序
    void inOrderRecur(TreeNode* head) {
		if (head == NULL) {
			return;
		}
		inOrderRecur(head->left); 
        cout<< head->val << " ";
		inOrderRecur(head->right);
	}
    //递归，后序
    void posOrderRecur(TreeNode* head) {
		if (head == NULL) {
			return;
		}
		posOrderRecur(head->left); 
		posOrderRecur(head->right);
        cout<< head->val << " ";
	}
    //非递归，先序
    void preOrderUnRecur(TreeNode* head) {
        if(!head) return;
        stack<TreeNode*>stk;
        stk.push(head);
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            cout<<cur->val<<" ";
            if(cur->right){
                stk.push(cur->right);
            }
            if(cur->left){
                stk.push(cur->left);
            }
        }
    }
    //非递归，中序
    void inOrderUnRecur(TreeNode* head) {
        if(!head) return;
        stack<TreeNode*>s;
        TreeNode* cur = head;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cout<<s.top()->val<<" ";
                s.pop();
                cur = cur->right;
            } 
        } 
    }
    //非递归，后序
    void posOrderUnRecur(TreeNode* head) {
        if(!head) return;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(head);
        //根右左，压入辅助栈，再弹出
        while(!s1.empty()){
            TreeNode* cur = s1.top();
            s1.pop();
            s2.push(cur);
            if(cur->left){
                s1.push(cur->left);
            }
            if(cur->right){
                s1.push(cur->right);
            }
        }
        while(!s2.empty()){
            cout<<s2.top()->val<<" ";
            s2.pop();
        }
    }
};

int main(){
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    Solution solu;
    cout<<"==============recursive==============\n";
    cout<<"pre-order: ";
    solu.preOrderRecur(head);
    cout<<", ";
    cout<<"in-order: ";
    solu.inOrderRecur(head);
    cout<<", ";
    cout<<"post-order: ";
    solu.posOrderRecur(head);
    cout<<"\n";
    cout<<"==============unrecursive==============\n";
    cout<<"pre-order: ";
    solu.preOrderUnRecur(head);
    cout<<", ";
    cout<<"in-order: ";
    //solu.inOrderUnRecur(head);
    cout<<", ";
    cout<<"post-order: ";
    solu.posOrderUnRecur(head);
    return 0;
}