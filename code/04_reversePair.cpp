#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
/*
逆序对问题 
在一个数组中，左边的数如果比右边的数大，则这两个数构成一个逆序对，请打印逆序对的个数。
*/


//将排好序的[L,M]与[M+1,R]合并成一个arr，并排好序，再返回Merge过程中产生的逆序对数
int merge(vector<int> &arr, int L, int M, int R) {
	vector<int>help(R - L + 1);
	//int help[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
	int res=0;
	while (p1 <= M && p2 <= R) {
		res += arr[p1] > arr[p2] ? M-p1+1 : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	//同一组内不再产生逆序对
	while (p1 <= M) {
		help[i++] = arr[p1++];
	}
	while (p2 <= R) {
		help[i++] = arr[p2++];
	}
	for (i = 0; i < help.size(); i++) {
		arr[L + i] = help[i];
	}
	return res;
}
//把arr[L..R]排好序,并返回[L..R]上的逆序对
int process(vector<int> &arr, int L, int R) {
	if (L == R) {//base case
		return 0;
	}
	int mid = L + ((R - L) >> 1);
	return process(arr, L, mid) + 
			process(arr, mid + 1, R) + 
			merge(arr, L, mid, R);
}

int reversePair(vector<int>&arr) {
	if (arr.empty() || arr.size() < 2) {
		return 0;
	}
	return process(arr, 0, arr.size() - 1);
}
void printVector(vector<int>arr){
	for(int i=0;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[arr.size()-1]<<endl;
}
int main(){
	//vector<int>arr{2,5,1,3,0,9,4};
	vector<int>arr{1,3,4,2,5};
	cout<<"逆序对个数："<<reversePair(arr)<<"\n";
	printVector(arr);
	arr = {5,3,9,6,7,0};
	cout<<"逆序对个数："<<reversePair(arr)<<"\n";
	return 0;
}

