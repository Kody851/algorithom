#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//针对nums[start..end]范围，将所有数与nums[end]比较，数组排成 [比end小的数, end,  比end大的数]， 返回中间数的下标。
int Partition(vector<int>& nums, int start, int end){
	int small=start-1;
	for(int i=start;i<end;i++){
		if(nums[i]<nums[end]){
			small++;
			//
			if(small!=i){
				//此时，[0..small-1]都比nums[end]小，nums[small]是第一个比nums[end]大的数
				//而当前数nums[i]<nums[end]，因此与nums[small]交换
				swap(nums[small],nums[i]);
			}
		}
	}
	//nums[small]是比nums[end]小的最右边的数
	small++; 
	//nums[small]是比nums[end]大的最左边的数
	swap(nums[small],nums[end]);
	//nums[end]变成中间的数，比它小的数为nums[0..small-1]共small个
	return small;
}
//将nums[start..end]排序
void helper(vector<int>& nums, int start, int end){
	if(start==end) return;
	int index=Partition(nums, start, end);
	if(index>start) helper(nums, start, index-1);
	if(index<end) helper(nums, index+1, end);
}
void QuickSort(vector<int>& nums){
	if (nums.empty() || nums.size() < 2) {
		return;
	}
    helper(nums, 0, nums.size()-1);
}

void printVector(vector<int>arr){
	for(int i=0;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[arr.size()-1]<<endl;
}
int main(){
	vector<int>arr{2,5,1,3,0,9,4};
	QuickSort(arr);
    //cout<<(rand()%11)/10.0;
	printVector(arr);
	return 0;
}

