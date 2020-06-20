#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include <queue>
using namespace std;
//对大致有序的数组排序，每个数字移动范围都不会超过k，k远小于数组大小
void sortedArrDistanceLessK(vector<int>& arr, int k) {
    // 小顶堆
    priority_queue<int, vector<int>, greater<int> > heap;
    //https://blog.csdn.net/weixin_36888577/article/details/79937886
    //priority_queue<int, vector<int>, less<int> > heap;//大顶堆
    int index = 0;
    for (; index <= (arr.size()<k ? arr.size() : k); index++) {
        heap.push(arr[index]);
    }
    int i = 0;
    for (; index < arr.size(); i++, index++) {
        heap.push(arr[index]);
        arr[i] = heap.top();
        heap.pop();
    }
    while (!heap.empty()) {
        arr[i++] = heap.top();
        heap.pop();
    }
}
void printVector(vector<int>arr){
	for(int i=0;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[arr.size()-1]<<endl;
}
int main(){
	vector<int>arr{2,5,1,3};
	sortedArrDistanceLessK(arr,3);
	printVector(arr);
	return 0;
}