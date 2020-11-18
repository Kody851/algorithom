#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
/*
换钱的方法数
换钱的最少货币数 
【题目】 
给定数组 arr，arr 中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，
再给定一个整数 aim，代表要找的钱数，求组成 aim 的最少货币数。
【举例】 
arr=[5,2,3]，aim=20。 4 张 5 元可以组成 20 元，其他的找钱方案都要使用更多张的货币，所以返回 4。 
arr=[5,2,3]，aim=0。 不用任何货币就可以组成 0 元，返回 0。 
arr=[3,5]，aim=2。 根本无法组成 2 元，钱不能找开的情况下默认返回-1。
*/

//index:0~arr.size()
//rest:0~aim
//如果自由使用arr[index..]的面值，组成rest这么多钱，返回方法数
int process(vector<int> arr, int index, int rest){
	//base case
	if(index==arr.size()){//无面值时
		return rest==0 ? 1 : 0;
	}
	int ways = 0;
	for(int piece=0; piece*arr[index]<=rest; piece++){//arr[index]用的张数不同，情况不同
		ways += process(arr, index+1, rest-piece*arr[index]);	
	}

	return ways;
}
int minCoinRecursion(vector<int> arr, int aim){
	if(arr.empty() || aim<0) return -1;
	return process(arr, 0, aim);
}

int minCoinDP(vector<int> arr, int aim){
	if(arr.empty() || aim<0) return -1;
	int n = arr.size();
	vector<vector<int>>dp(n+1, vector<int>(aim+1));
	
	dp[n][0] = 1;
	for(int index=n-1; index>=0; index--){
		for(int rest=0; rest<=aim; rest++){
			/*for(int piece=0; piece*arr[index]<=rest; piece++){
				dp[index][rest] += dp[index+1][rest-piece*arr[index]];
			}*/
			dp[index][rest] = dp[index+1][rest]; 
			if(rest-arr[index]>=0){
				dp[index][rest] += dp[index][rest-arr[index]];//省了步骤
			}
		}
	}
	return dp[0][aim];
}
int main(){
	
	cout<<"暴力递归："<<minCoinRecursion(vector<int>{5,2,3}, 20)<<"\n";
	cout<<"动态规划："<<minCoinDP(vector<int>{5,2,3}, 20)<<"\n";
    return 0;
}