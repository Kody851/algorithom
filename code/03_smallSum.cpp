#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
/*
小和问题 
在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和。 
例子:[1,3,4,2,5] 1左边比1小的数，没有; 3左边比3小的数，1; 4左 边比4小的数，1、3; 
2左边比2小的数，1; 5左边比5小的数，1、3、4、 2; 所以小和为1+1+3+1+1+3+4+2=16
*/
//小和可以理解为在归并过程中，merge时，左边p1比右边小p2，则右边[p2..R]范围内的值都含有有p1该值的小和


//将排好序的[L,M]与[M+1,R]合并成一个arr，并排好序，再返回Merge过程中产生的小和
int merge(vector<int> &arr, int L, int M, int R) {
	vector<int>help(R - L + 1);
	//int help[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
	int res=0;
	while (p1 <= M && p2 <= R) {
		res += arr[p1] < arr[p2] ? (R-p2+1)*arr[p1] : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	//同一组内不再产生小和
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
//把arr[L..R]排好序,并返回[L..R]上的小和
int process(vector<int> &arr, int L, int R) {
	if (L == R) {//base case
		return 0;
	}
	int mid = L + ((R - L) >> 1);
	return process(arr, L, mid) + 
			process(arr, mid + 1, R) + 
			merge(arr, L, mid, R);
}

int smallSum(vector<int>&arr) {
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
	cout<<"小和："<<smallSum(arr)<<"\n";
	printVector(arr);
	return 0;
}

