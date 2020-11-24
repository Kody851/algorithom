#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void mergesort(vector<int>&arr){
    if(arr.empty() || arr.size()<2) return;
    process(arr, 0, arr.size()-1);
}
void process(vector<int>&arr, int L, int R){
    if(L==R) return;
    int mid = L + ((R-L)>>1);
    process(arr, L, mid);
    process(arr, mid+1, R);
    merge(arr, L, R, mid);
}
void merge(vector<int>&arr, int L, int R, int mid){
    vector<int>help(R-L+1);
    int p1 = L, p2 = mid+1, i=0;
    while(p1<=mid && p2<=R){
        help[i++] = arr[p1]<arr[p2] ? arr[p1++] : arr[p2++];
    }
    while(p1<=mid){
        help[i++] = arr[p1++];
    }
    while(p2<=R){
        help[i++] = arr[p2++];
    }
    for(int i=0; i<help.size(); i++){
        arr[L+i] = help[i];
    }
}