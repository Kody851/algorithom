#include<iostream>
using namespace std;
//折纸N次，问折痕从上到下是什么样
/*
请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，
压出折痕后展开。 此时折痕是凹下去的，即折痕突起的方向指向纸条的背面。 
如果从纸条的下边向上方连续对折2次，压出折痕后展开，此时有三条折痕，
从上到下依次是下折痕、下折痕和上折痕。 给定一个输入参数N，
代表纸条都从下边向上方连续对折N次。 请从上到下打印所有折痕的方向。 
例如:N=1时，打印: down N=2时，打印: down down up
*/
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