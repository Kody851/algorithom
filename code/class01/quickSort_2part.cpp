#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void mySwap(vector<int> &arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
}
// 这是一个处理arr[L..R]的函数
	// 默认以arr[R]做划分，arr[R] -> p     <=p     >p
	// 返回大于区的左边界
int partition(vector<int> &arr, int L, int R) {
		//int less = L - 1; // <区右边界
		int more = R; // >区左边界 R+1
		int index = L;
        while (index < more) { // L表示当前数的位置   arr[R]  ->  划分值
			if (arr[index] <= arr[R]) { // 当前数   <  划分值
                index++;
			} 
            else{ // 当前数   >  划分值
				mySwap(arr, --more, index);
			} 
		}
		mySwap(arr, more, R);
		return more;//arr[more]=p
	}
void quickSortInterval(vector<int>&arr, int L, int R) {
		if (L < R) {
			int p = partition(arr, L, R);
			quickSortInterval(arr, L, p - 1); // < 区
			quickSortInterval(arr, p + 1, R); // > 区
		}
	}
void quickSort(vector<int>&arr) {
	if (arr.empty() || arr.size() < 2) {
		return;
	}
    quickSortInterval(arr, 0, arr.size() - 1);
	
}

void printVector(vector<int>arr){
	for(int i=0;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[arr.size()-1]<<endl;
}
int main(){
	vector<int>arr{2,5,1,3,0,9,4};
	quickSort(arr);
    //cout<<(rand()%11)/10.0;
	printVector(arr);
	return 0;
}

