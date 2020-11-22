#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
#include<math.h> //pow
/*
Bob的生存概率 
【题目】 
给定五个参数n,m,i,j,k。表示在一个N*M的区域，Bob处在(i,j)点，
每次Bob等概率的向上、 下、左、右四个方向移动一步，Bob必须走K步。
如果走完之后，Bob还停留在这个区域上， 就算Bob存活，否则就算Bob死亡。
请求解Bob的生存概率，返回字符串表示分数的方式。
*/
//=====递归==========
//process : Bob处在(row,col)点，走rest步，可获得的生存点数
long process(int N, int M, int row, int col, int rest){
	if(row<0 || row>=N || col<0 || col>=M || rest<0){
		return 0;
	}
	else if(rest == 0){
		return 1;
	}
	return process(N, M, row-1, col, rest-1)
			+ process(N, M, row+1, col, rest-1)
			+ process(N, M, row, col-1, rest-1)
			+ process(N, M, row, col+1, rest-1);
}
double Bob(int N, int M, int i, int j, int k){//返回概率值
	long SumPossible = pow(4,k); //   1<<(2*k)
	long survive = process(N,M,i,j,k);
	return (double) survive/SumPossible;
}
long gcd(long m, long n) {//两数的最大公约数
		return n == 0 ? m : gcd(n, m % n);
}
string Bobs(int N, int M, int i, int j, int k){//返回分数形式
	long SumPossible = pow(4,k); //   1<<(2*k)
	long survive = process(N,M,i,j,k);
	long gcdnum = gcd(SumPossible,survive);
	return to_string(survive/gcdnum) + "/" + to_string(SumPossible/gcdnum);
}
//======================

//=====DP==========
double BobDP(int N, int M, int i, int j, int k){
	//dp[row][col][rest]表示从(row,col)走rest步，落到N*M区域的点数
	//int dp[N+2][M+2][k+1]={{{0}}};//并不行

	//本题从递归改到动态规划，需要修改坐标起始点。
	//坐标要从1~N,1~M。同时dp范围选为0~N+1(也就是N+2大小) 。否则会出现数组索引越界。
	//返回结果改为(i+1, j+1)
	vector<vector<vector<int>>> dp(N+2, vector<vector<int>>(M+2, vector<int>(k+1)));	
	for(int rest=0; rest<=k; rest++){
		for(int row=1; row<=N; row++){//注意是1~N
			for(int col=1; col<=M; col++){
				if(rest == 0){//处于N*M区域，还剩0步
					dp[row][col][rest] = 1;
				}
				else{
					dp[row][col][rest] = dp[row-1][col][rest-1]
										+ dp[row+1][col][rest-1]
										+ dp[row][col-1][rest-1]
										+ dp[row][col+1][rest-1];
				}
			}
		}
	}
	//往4个方向走k步的总的可能点数
	long SumPossible = pow(4,k); //   1<<(2*k)
	long survive = dp[i+1][j+1][k];//(i+1, j+1)
	return (double) survive/SumPossible;

}
//======================
int main(){
	cout<<"暴力递归："<<Bob(10,10,3,2,5)<<","<<Bobs(10,10,3,2,5)<<"\n";;
	cout<<"动态规划："<<BobDP(10,10,3,2,5)<<"\n";
    return 0;
}