#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
/*1、递归让左半边有序、右半边有序；2、两边归并，用1个辅助空间，两个指针分别从两边最小值开始，
哪个小就拷贝至辅助空间，同时指针右移; 3、全拷贝完，把辅助空间拷贝回原数组*/
void mySwap(vector<int> &arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
}
void merge(vector<int> &arr, int L, int M, int R) {
	vector<int>help(R - L + 1);
	//int[] help = new int[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
	while (p1 <= M && p2 <= R) {
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= M) {
		help[i++] = arr[p1++];
	}
	while (p2 <= R) {
		help[i++] = arr[p2++];
	}
	for (i = 0; i < help.size(); i++) {
		arr[L + i] = help[i];
	}
}
//把arr[L..R]排好序
void process(vector<int> &arr, int L, int R) {
	if (L == R) {//base case
		return;
	}
	int mid = L + ((R - L) >> 1);
	process(arr, L, mid);
	process(arr, mid + 1, R);
	merge(arr, L, mid, R);
}

void mergeSort(vector<int>&arr) {
	if (arr.empty() || arr.size() < 2) {
		return;
	}
	process(arr, 0, arr.size() - 1);
}
void printVector(vector<int>arr){
	for(int i=0;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[arr.size()-1]<<endl;
}
int main(){
	vector<int>arr{2,5,1,3,0,9,4};
	mergeSort(arr);
	printVector(arr);
	return 0;
}

