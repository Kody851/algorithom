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
            cout<<cur->val<<" ";
            stk.pop();
            if(cur->right){
                stk.push(cur->right);
            }
            if(cur->left){
                stk.push(cur->left);
            }
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
    cout<<"==============unrecursive==============\n";
    cout<<"pre-order: ";
    solu.preOrderUnRecur(head);
    return 0;
}