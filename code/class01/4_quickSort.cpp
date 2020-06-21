#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void mySwap(vector<int> &arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
}
// 这是一个处理arr[l..r]的函数
	// 默认以arr[r]做划分，arr[r] -> p     <p   ==p   >p
	// 返回等于区域(左边界，右边界), 所以返回一个长度为2的数组res, res[0] res[1]
vector<int> partition(vector<int> &arr, int L, int R) {
		int less = L; // <区右边界的下一个
		int more = R; // >区左边界的前一个 R+1
		int index = L;
        while (index < more) { // L表示当前数的位置   arr[R]  ->  划分值
			if (arr[index] < arr[R]) { // 当前数   <  划分值
				mySwap(arr, less++, index++);
			} else if (arr[index] > arr[R]) { // 当前数   >  划分值
				mySwap(arr, --more, index);
			} else {
				index++;
			}
		}
		mySwap(arr, more, R);
		return vector<int> { less, more };//more-1
	}
void quickSortInterval(vector<int>&arr, int L, int R) {
		if (L < R) {
            mySwap(arr, L + rand()%(R - L + 1), R);
			vector<int> p = partition(arr, L, R);
			quickSortInterval(arr, L, p[0] - 1); // < 区
			quickSortInterval(arr, p[1] + 1, R); // > 区
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

