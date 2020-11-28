#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
void mySwap(vector<int> &arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
}
//由左至右逐个插入建堆
//arr[0..index-1]已经是大根堆了，这时index位置插入新元素，让arr[0..index]变成大根堆
void heapInsert(vector<int>&arr, int index){
    while(arr[index]>arr[(index-1)/2]){//不停和父节点比较
        mySwap(arr,index,(index-1)/2);
        index = (index-1)/2;
    }
}
//把[index..heapSize-1]堆化
//某个数在index位置，与左右孩子中较大的比较，如果小于孩子，则两者互换，index上的数下沉，继续往下，直到叶节点（左孩子越界）
void heapify(vector<int>&arr, int index, int heapSize){
    int left = 2*index+1;
    while(left<heapSize){
        int max = left+1<heapSize && arr[left+1]>arr[left] ? left+1 : left;
        max = arr[max]>arr[index] ? max : index;
        if(max==index) break;
        mySwap(arr, index, max);
        index = max;
        left = 2*index+1;
    }
}
void heapSort(vector<int>&arr) {
	if (arr.empty() || arr.size() < 2) {
		return;
	}
    //数组建堆
    for(int i=0;i<arr.size();i++){
        heapInsert(arr,i);
    }	
    //把顶与数组末尾交换，数组末尾元素断开，其余元素堆化；重复
    int heapSize = arr.size();
    while(heapSize>0){
        mySwap(arr,0,--heapSize);
        heapify(arr,0,heapSize);
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

