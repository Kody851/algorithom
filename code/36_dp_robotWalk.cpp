#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
/*
机器人达到指定位置方法数 
【题目】
假设有排成一行的 N 个位置，记为1~N，N一定大于或等于2。开始时机器人在其中的M位置上(M一定是1~N中的一个)，
机器人可以往左走或者往右走，如果机器人来到 1 位置， 那么下一步只能往右来到2位置;如果机器人来到N位置，
那么下一步只能往左来到N-1位置。 规定机器人必须走K步，最终能来到P位置(P 也一定是 1~N 中的一个)的方法有多少种。
给定四个参数 N、M、K、P，返回方法数。 
【举例】 
N=5,M=2,K=3,P=3 上面的参数代表所有位置为 1 2 3 4 5。机器人最开始在 2 位置上，必须经过 3 步，
最后到 达 3 位置。走的方法只有如下 3 种: 
1)从2到1，从1到2，从2到3 
2)从2到3，从3到2，从2到3 
3)从2到3，从3到4，从4到3 
所以返回方法数3。 N=3,M=1,K=3,P=3 上面的参数代表所有位置为 1 2 3。
机器人最开始在 1 位置上，必须经过 3 步，最后到达 3 位置。怎么走也不可能，所以返回方法数 0。
*/
	// N : 位置为1 ~ N，固定参数
	// cur : 当前在cur位置，可变参数
	// rest : 还剩res步没有走，可变参数
	// P : 最终目标位置是P，固定参数
	// 该函数的含义：只能在1~N这些位置上移动，
	// 当前在cur位置，走完rest步之后，停在P位置的方法数作为返回值返回

int walk(int N, int cur, int rest, int P){
	// 如果没有剩余步数了，当前的cur位置就是最后的位置
	// 如果最后的位置停在P上，那么之前做的移动是有效的
	// 如果最后的位置没在P上，那么之前做的移动是无效的
	if(rest == 0){
		return cur==P ? 1 : 0;
	}
	// 如果还有rest步要走，而当前的cur位置在1位置上，那么当前这步只能从1走向2
	// 后续的过程就是，来到2位置上，还剩rest-1步要走
	if(cur == 1){
		return walk(N, cur+1, rest-1, P);
	}
	if(cur == N){
		return walk(N, cur-1, rest-1, P);
	}
	// 如果还有rest步要走，而当前的cur位置在中间位置上，那么当前这步可以走向左，也可以走向右
	// 走向左之后，后续的过程就是，来到cur-1位置上，还剩rest-1步要走
	// 走向右之后，后续的过程就是，来到cur+1位置上，还剩rest-1步要走
	// 走向左、走向右是截然不同的方法，所以总方法数要都算上
	return walk(N, cur-1, rest-1, P) + walk(N, cur+1, rest-1, P);
}
int ways(int N, int M, int K, int P){
	// 参数无效直接返回0
	if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N) {
		return 0;
	}
	// 总共N个位置，从M点出发，还剩K步，返回最终能达到P的方法数
	return walk(N, M, K, P);
}
int waysDP(int N, int M, int K, int P){
	if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N) {
		return 0;
	}
	//dp[cur][rest]的含义是当前在cur位置，还有rest步要走，最终能到P位置的方法数。
	vector<vector<int>>dp(N+1,vector<int>(K+1,0));
	//int dp[N+1][K+1]={{}};//int len = sizeof(num) / sizeof(num[0]);
	dp[P][0] = 1;
	for(int rest=1; rest<=K; rest++){//先遍历rest，因为每个值都与rest-1相关，rest=0已定义。dp表是一列一列得到的。
		dp[1][rest] = dp[2][rest-1];
		dp[N][rest] = dp[N-1][rest-1];
		for(int cur=2; cur<N; cur++){//cur与cur+1、cur-1都可能有关
			dp[cur][rest] = dp[cur-1][rest-1] + dp[cur+1][rest-1];
		}
	}
	return dp[M][K];
}
int main(){
	//N=5,M=2,K=3,P=3
	cout<<"暴力递归解法："<<ways(5, 2, 3, 3)<<"\n";
	cout<<"动态规划解法："<<waysDP(5, 2, 3, 3)<<"\n";
	
	int arr[3][2]={};//{0}	
	cout<<arr[0][1]<<arr[0][2];
	
    return 0;
}