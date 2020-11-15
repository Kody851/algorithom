#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
/*
换钱的最少货币数 
【题目】 
给定数组 arr，arr 中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，
再给定一个整数 aim，代表要找的钱数，求组成 aim 的最少货币数。
【举例】 
arr=[5,2,3]，aim=20。 4 张 5 元可以组成 20 元，其他的找钱方案都要使用更多张的货币，所以返回 4。 
arr=[5,2,3]，aim=0。 不用任何货币就可以组成 0 元，返回 0。 
arr=[3,5]，aim=2。 根本无法组成 2 元，钱不能找开的情况下默认返回-1。
*/
//在arr[index..]上的最少货币数。
//index:0~arr.size()
//rest:0~aim
int process(vector<int> arr, int aim, int index, int rest){
	//base case
	
}
int minCoinRecursion(vector<int> arr, int aim){
	if(arr.empty() || aim<0) return -1;
	return process(arr, aim, 0, aim);
}
int main(){
	
	
    return 0;
}