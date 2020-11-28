#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
void mySwap(vector<int>&arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void heapInsert(vector<int>&arr, int i){
    
}
void heapSort(vector<int>&arr){
    if(arr.size()<2) return;
    for(int i=0;i<arr.size();i++){
        heapInsert(arr, i);
    }
    int heapSize = arr.size();
    while(heapSize>0){
        mySwap(arr, 0, --heapSize);
        heapify(arr, 0, heapSize);
    }
}

void printVector(vector<int>arr){
	for(int i=0;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
    cout<<arr[arr.size()-1]<<endl;
}
int main(){
	vector<int>arr{2,5,1,3,0,9,4};
	heapSort(arr);
	printVector(arr);
	return 0;
}

