#include<iostream>
#include<queue>
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
    void preOrderRecur(TreeNode* head) {
		if (head == NULL) {
			return;
		}
		cout<< head->val << " ";
		preOrderRecur(head->left); 
		preOrderRecur(head->right);
	}
    string serialByPre(TreeNode* head) {
		if (head == NULL) {
			return "#_";
		}
		string res = to_string(head->val) + "_";//std::to_string()  int转string
		res += serialByPre(head->left);
		res += serialByPre(head->right);
		return res;
	}
    TreeNode* reconByPreString(string preStr) {
		vector<string> values = preStr.split("_");//https://www.zhihu.com/question/36642771
		queue<string> q;
		for (int i = 0; i != values.size(); i++) {
			q.push(values[i]);
		}
		return reconPreOrder(q);
	}

	TreeNode* reconPreOrder(queue<string> q) {
		string value = q.front();
        q.pop();
		if (value.equals("#")) {
			return NULL;
		}
		TreeNode* head = new TreeNode(Integer.valueOf(value));
		head->left = reconPreOrder(q);
		head->right = reconPreOrder(q);
		return head;
	}
};

int main(){
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    Solution solu;
    //cout<<"pre-order: ";
    //solu.preOrderRecur(head);
    cout<<"先序-序列化：";
    cout<<solu.serialByPre(head);
    
    return 0;
}