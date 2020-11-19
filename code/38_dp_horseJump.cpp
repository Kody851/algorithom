#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
/*
象棋中马的跳法 
【题目】 
请同学们自行搜索或者想象一个象棋的棋盘，然后把整个棋盘放入第一象限，棋盘的最左下角是(0,0)位置。
那么整个棋盘就是横坐标上9条线、纵坐标上10条线的一个区域。给你三个参数，x，y，k，
返回如果“马”从(0,0)位置出发，必须走k步，最后落在(x,y)上的方法数 有多少种？
*/

int horseJump(int x, int y, int k){
	if(x<0 || x>8 || y<0 || y>9 || k<0){
		return 0;
	}
	int dp[9][10][k+1];
	

	return dp[0][0][k];
}

int main(){
	
	cout<<"暴力递归："<<minCoinRecursion(vector<int>{5,2,3}, 20)<<"\n";
	cout<<"动态规划："<<minCoinDP(vector<int>{5,2,3}, 20)<<"\n";
    return 0;
}