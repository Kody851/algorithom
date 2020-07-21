#include<iostream>
using namespace std;
//折纸N次，问折痕从上到下是什么样
class Solution{
    public:
        void printAllFolds(int N) {
		    printProcess(1, N, true);
	    }

	// 递归过程，来到了某一个节点，
	// i是节点的层数，N一共的层数，concave == true  凹    concave == false 凸
    //其实是这样一个二叉树的中序遍历：头结点是凹折痕；所有左树的头结点都是凹折痕；所有右树的头结点都是凸折痕；O(N)空间
	void printProcess(int i, int N, bool concave) {
		if (i > N) {
			return;
		}
		printProcess(i + 1, N, true);
		cout<<(concave ? "凹 " : "凸 ");
		printProcess(i + 1, N, false);
	}
};

int main(){
    Solution solu;
    int N = 3;
    solu.printAllFolds(N);
    return 0;
}