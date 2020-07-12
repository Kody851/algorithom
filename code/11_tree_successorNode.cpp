#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;//父节点
    TreeNode(int x) :
            val(x), left(NULL), right(NULL),parent(NULL) {
    }
};
class Solution{
public:
    //返回给定节点的后继节点：中序遍历中的下一个节点
    TreeNode* successorNode(TreeNode* node){
        if(!node) return NULL;
        //若node有右孩子，则后继为右孩子的最左孩
        if(node->right){
            TreeNode* cur = node->right;
            while(cur->left){
                cur = cur->left;
            }
            return cur;
        }
        //若node无右孩，则往上找，直到某个节点是其父节点的左孩，则后继为该父。
        else{
            TreeNode* cur = node;
            TreeNode* p = node->parent;           
            while( p && p->right==cur ){
                cur = p;
                p = p->parent;
            }
            return p;
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
    return 0;
}