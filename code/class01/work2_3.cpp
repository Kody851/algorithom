#include<iostream>
#include<vector>
using namespace std;
/*
对于一个无序数组A，请设计一个算法，求出需要排序的最短子数组的长度。
给定一个整数数组A及它的大小n，请返回最短子数组的长度。
测试样例：
[1,5,3,4,2,6,7],7
返回：4
*/
int findShortest(vector<int> A, int n) {
    return 4;
}

int main(){
    vector<int>A{1,5,3,4,2,6,7};
    int n = 7;
    cout<<findShortest(A,n);

    return 0;
    
}