#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
/*
// 给定一个arr，i -> arr[i]
	// 返回的结果
	// int[][]  i*2 含义：
	// [
	//    [0],[1]  长度为2
	//    [0],[1]  长度为2
	//    [0],[1]  长度为2
	// ]
	// res[i][0]  i位置的数，左边离i最近，比i小的数，位置是啥
	// res[i][1]  i位置的数，右边离i最近，比i小的数，位置是啥
*/
void printVector(vector<int>arr){
	int i=0;
	for(;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[i]<<"\n";
}
//不考虑重复数字
vector<vector<int>> getNearLessNoRepeat(vector<int>arr){
	vector<vector<int>> res(arr.size(),vector<int>(2));//注意二维数组的初始化方式
	stack<int>stk;
	for (int i = 0; i < arr.size(); i++) { // i -> arr[i]
		while (!stk.empty() && arr[stk.top()] > arr[i]) {
			// 当前弹出的东西 ： popIndex  -> arr[popIndex]
			int popIndex = stk.top();
			stk.pop();
			int leftLessIndex = stk.empty() ? -1 : stk.top();
			res[popIndex][0] = leftLessIndex;
			res[popIndex][1] = i;
		}
		stk.push(i);
	}
	while (!stk.empty()) {
		int popIndex = stk.top();
		stk.pop();
		int leftLessIndex = stk.empty() ? -1 : stk.top();
		res[popIndex][0] = leftLessIndex;
		res[popIndex][1] = -1;
	}
	return res;
}
//考虑重复数字
vector<vector<int>> getNearLess(vector<int>arr){
	vector<vector<int>> res(arr.size(),vector<int>(2));
	stack<vector<int>>stk;
	for (int i = 0; i < arr.size(); i++) { // i -> arr[i]
		while (!stk.empty() && arr[stk.top()[0]] > arr[i]) {
			// 当前弹出的东西 ： popIndex  -> arr[popIndex]
			vector<int> popIndexVector = stk.top();
			stk.pop();
			int leftLessIndex = stk.empty() ? -1 : stk.top()[stk.top().size()-1];
			for(auto popIndex: popIndexVector){
				res[popIndex][0] = leftLessIndex;
				res[popIndex][1] = i;
			}			
		}
		if(!stk.empty() && arr[stk.top()[0]] == arr[i]){
			stk.top().push_back(i);
		}
		stk.push(vector<int>{i});
	}
	while (!stk.empty()) {
		vector<int> popIndexVector = stk.top();
		stk.pop();
		int leftLessIndex = stk.empty() ? -1 : stk.top()[stk.top().size()-1];
		for(auto popIndex: popIndexVector){
			res[popIndex][0] = leftLessIndex;
			res[popIndex][1] = -1;
		}			
	}
	return res;
}
int main(){
	for(auto i: getNearLessNoRepeat({1,2,4,3})){
		printVector(i);
	}
	cout<<"==============";
	for(auto i: getNearLess({1,2,1,3})){
		printVector(i);
	}
    return 0;
}