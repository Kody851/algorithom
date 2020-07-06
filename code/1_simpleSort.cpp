#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
//3种简单排序
void mySwap(vector<int> &arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
}
//选择排序
void selectionSort(vector<int>&arr) {
	if (arr.empty() || arr.size() < 2) {
		return;
	}
	for (int i = 0; i < arr.size() - 1; i++) { // i ~ N-1
		int minIndex = i;
		for (int j = i + 1; j < arr.size(); j++) { // i ~ N-1 上找最小值的下标 
			minIndex = arr[j] < arr[minIndex] ? j : minIndex;
		}
		//swap(arr[i],arr[minIndex]);
		mySwap(arr, i, minIndex);
	}
}
//冒泡排序
void bubbleSort(vector<int>&arr) {
	if (arr.empty() || arr.size() < 2) {
		return;
	}
	for (int e = arr.size() - 1; e > 0; e--) { // 0 ~ e
		for (int i = 0; i < e; i++) {
			if (arr[i] > arr[i + 1]) {
				mySwap(arr, i, i + 1);
			}
		}
	}
}
//插入排序
void insertionSort(vector<int>&arr) {
	if (arr.empty() || arr.size() < 2) {
		return;
	}
	// 0~0 有序的
	// 0~i 想有序
	for (int i = 1; i < arr.size(); i++) { // 0 ~ i 做到有序
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
			mySwap(arr, j, j + 1);
		}
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
	//selectionSort(arr);
	//bubbleSort(arr);
	insertionSort(arr);
	printVector(arr);
	return 0;
}

