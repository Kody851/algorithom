//二叉树的递归套路 -树型DP
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
/*
struct Info {
    bool isBST;
    int min;
    int max;
    Info(bool is, int mi, int ma):
        isBST(is),min(mi),max(ma){
    }
};
*/

class Solution{
public:
    //=======================================================
    //二叉搜索树：每个子树的左边比他小、右边比他大。||空树
    class InfoBST{
    public:
        bool isBST;
        int min;
        int max;
        InfoBST(bool is, int mi, int ma){
            isBST = is;
            min = mi;
            max = ma;
        }
    };
    InfoBST* process(TreeNode* x){
        if(!x) return NULL;
        InfoBST* leftData = process(x->left);
        InfoBST* rightData = process(x->right);
        int min = x->val;
        int max = x->val;
        if(!leftData){
            min = min<leftData->min ? min : leftData->min;
            max = max>leftData->max ? max : leftData->max;
        }
        if(!rightData){
            min = min<rightData->min ? min : rightData->min;
            max = max>rightData->max ? max : rightData->max;
        }
        bool isBST = false;
        if(
            (leftData  ? (leftData->isBST  &&  leftData->max < x->val) : true)
			    &&
			(rightData ? (rightData->isBST  && rightData->min > x->val) : true)	  	
		) {isBST = true;}
        return new InfoBST(isBST,min,max);
    }
    bool isBinarySearchTree(TreeNode* head){
        //左、右子树是BST && 左子树的最大值<当前值<右子树的最小值
        if(!head) return true;
        return process(head)->isBST;
    }
    //==========================================================
    //满二叉树：二叉树的最大高度为h，则节点个数为n=2^h-1。 ||空树
    class InfoFBT{
        public:
            int height;
            int nodes;
            InfoFBT(int h, int n){
                height = h;
                nodes = n;
            }
    };
    InfoFBT* processFBT(TreeNode* x){
        if(!x) return new InfoFBT(0,0);
        InfoFBT* leftData = processFBT(x->left);
        InfoFBT* rightData = processFBT(x->right);
        int height = max(leftData->height,rightData->height) + 1;
        int nodes = leftData->nodes + rightData->nodes +1;
        return new InfoFBT(height,nodes);
    }
    bool isFullBinaryTree(TreeNode* head){
        if(!head) return true;
        InfoFBT* data = processFBT(head);
        return data->nodes == (1 << data->height - 1);
    }
    //=======================================================
    //平衡二叉树：每一颗子树，左树和右树的高度差不超过1。||空树
    class InfoBT{
        public:
            bool isBT;
            int height;
            InfoBT(bool is, int h){
                isBT = is;
                height = h;
            }           
    };
    InfoBT* processBT(TreeNode* x){
        if(!x) return new InfoBT(true,0);
        InfoBT* leftData = processBT(x->left);
        InfoBT* rightData = processBT(x->right);
        int height = max(leftData->height,rightData->height) + 1;
        bool isBT = leftData->isBT && rightData->isBT 
                && abs(leftData->height - rightData->height)<=1;
        return new InfoBT(isBT,height);
    }
    bool isBalanceTree(TreeNode* head){
        //左右都平衡 && 左右高度差不超过1
        return processBT(head)->isBT;
    }
    //=========================================================
    //完全二叉树：要么是满的，要么处于满的路上。   
    bool isCompleteBinaryTree(TreeNode* head){
        if(!head) return true;
        bool needLeaf = false;
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        queue<TreeNode*>q;
        q.push(head);
        while(!q.empty()){
            TreeNode*cur = q.front();
            q.pop();
            l = cur->left;
            r = cur->right;
            if(
                (l==NULL && r!=NULL)//有右无左
                ||
                (needLeaf && (l || r))//如果遇到了不双全的节点之后，又发现当前节点不是叶节点
              ){
                  return false;
            }
            if(l) q.push(l);
            if(r) q.push(r);
            if( (l!=NULL && r==NULL) || (l==NULL && r==NULL) )//if(l==NULL || r==NULL)
                needLeaf = true;
        }
        return true;
        //对于每个节点不能有右无左 && 在层次遍历时，一旦遇到孩子不双全的节点，后续所有节点必须是叶节点
    }
    //==========================================================
    //给定两个二叉树的节点node1和node2，找到他们的最低公共祖先节点
    class InfoLA{
        public:
            bool findo1;
            bool findo2;
            TreeNode *findAns;
            InfoLA(bool f1,bool f2,TreeNode* f){
                findo1 = f1;
                findo2 = f2;
                findAns = f;
            }
    };
    InfoLA* processLA(TreeNode* x, TreeNode*o1, TreeNode*o2){
        if(!x) return new InfoLA(false,false,NULL);
        InfoLA* l = processLA(x->left,o1,o2);
        InfoLA* r = processLA(x->right,o1,o2);
        //左或右有发现最低公共祖先
        if(l->findAns) return new InfoLA(true,true,l->findAns);
        if(r->findAns) return new InfoLA(true,true,r->findAns);
        //左右都没有发现最低公共祖先
        //o1和o2在x处交汇
        if( (l->findo1 && r->findo2) || (l->findo2 && r->findo1) ){
            return new InfoLA(true,true,x);
        }
        //左右两树只包含o1，或只包含o2，或都没发现
        if(l->findo1 || r->findo1){
            if(x==o2) return new InfoLA(true,true,x);
            else return new InfoLA(true,false,NULL);
        }
        if(l->findo2 || r->findo2){
            if(x==o1) return new InfoLA(true,true,x);
            else return new InfoLA(false,true,NULL);
        }
        //都没发现
        return new InfoLA(x==o1,x==o2,NULL);
    }
    TreeNode* lowestAncestor(TreeNode* head, TreeNode*o1, TreeNode*o2){
        return processLA(head,o1,o2)->findAns;
    }
    //==========================================================
};

int main(){
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    Solution solu;
    //cout<<"是二叉搜索树："<<solu.isBinarySearchTree(head);
    cout<<"是满二叉树："<<solu.isFullBinaryTree(head)<<"\n";
    cout<<"是平衡二叉树："<<solu.isBalanceTree(head);
    return 0;
}