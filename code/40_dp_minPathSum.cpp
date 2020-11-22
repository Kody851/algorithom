#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
#include<math.h> //pow
/*
矩阵的最小路径和 
【题目】 
给定一个矩阵 mat，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，
路径上所有的数字累加起来就是路径和，返回所有的路径中最小的路径和。 
【举例】 如果给定的 mat 如下: 1359 8134 5061 8840 
路径 1，3，1，0，6，1，0 是所有路径中路径和最小的，所以返回12
*/
//=====递归==========
//从mat[i][j]出发，到达右下角mat[m-1][n-1]的最小路径和
int process(vector<vector<int>> mat, int i, int j){
	int m = mat.size();
	int n = mat[0].size();
	if(i == m-1 && j == n-1){
		return mat[m-1][n-1];
	}
	//边界问题其实是写完返回函数后才思考出
	if(i == m || j == n){
		return INT_MAX;
	}
	return mat[i][j] + min(process(mat, i, j+1),  process(mat, i+1, j));//只有右下角的点才可能两边都越界

/*	if(i == m){
		return INT_MAX - mat[i-1][j];
	}
	if(j == n){
		return INT_MAX - mat[i][j-1];
	}
	return min(mat[i][j] + process(mat, i, j+1),  mat[i][j] + process(mat, i+1, j));*/
}

int minPath(vector<vector<int>> mat){
	if(mat.empty()) return 0;
	return process(mat, 0, 0);
}
//======================

//=====DP==========
int minPathDP(vector<vector<int>> mat){
	if(mat.empty()) return 0;
	int m = mat.size();
	int n = mat[0].size();
	//从mat[i][j]出发，到达右下角mat[m-1][n-1]的最小路径和
	vector<vector<int>> dp(m+1, vector<int>(n+1));
	for(int i=m-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			if(i==m || j==n){
				dp[i][j] = INT_MAX;
			}
			if(i==m-1 && j==n-1){	//dp[m-1][n-1] =  mat[m-1][n-1];
				dp[i][j] = mat[i][j];
			}
			dp[i][j] = mat[i][j] + min(dp[i][j+1], dp[i+1][j]);
		}
	}
	return dp[0][0];
}
//======================
int main(){
	cout<<"暴力递归："<<minPath(vector<vector<int>>{{1,3,5,9}, {8,1,3,4}, {5,0,6,1}, {8,8,4,0}}) <<"\n";;
	cout<<"动态规划："<<minPathDP(vector<vector<int>>{{1,3,5,9}, {8,1,3,4}, {5,0,6,1}, {8,8,4,0}}) <<"\n";
    return 0;
}