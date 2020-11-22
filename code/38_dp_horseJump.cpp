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
//=====递归==========
int process(int i, int j, int step){//从(0,0)位置出发，走step步，到达(i,j)的方法数
	if(i<0 || i>8 || j<0 || j>9 || step<0){
		return 0;
	}
	if(step==0){//base case
		return (i==0 && j==0) ? 1 : 0;
	}
	return process(i-2, j-1, step-1)
			+ process(i-2, j+1, step-1)
			+ process(i-1, j-2, step-1)
			+ process(i-1, j+2, step-1)
			+ process(i+1, j-2, step-1)
			+ process(i+1, j+2, step-1)
			+ process(i+2, j-1, step-1)
			+ process(i+2, j+1, step-1);
}
int horseJump(int x, int y, int k){	
	return process(x, y, k);
}
//======================
//=====DP==========
int getDpValue(vector<vector<vector<int>>> dp, int i, int j, int step){
		if(i<0 || i>8 || j<0 || j>9 || step<0){
			return 0;
		}
		else{
			return dp[i][j][step];
		}
	}
int horseJumpDP(int x, int y, int k){
	if(x<0 || x>8 || y<0 || y>9 || k<0){
		return 0;
	}
	//vector<vector<int> >a(1, vector<int>(2));
	vector<vector<vector<int>>> dp(9, vector<vector<int> >(10, vector<int>(k+1)));//int dp[9][10][k+1];
	//dp[i][j][step] 表示 从(0,0)位置出发，走step步，到达(i,j)的方法数
	dp[0][0][0] = 1;
	for(int step=1;step<=k;step++){
		for(int i=0;i<=8;i++){
			for(int j=0;j<=9;j++){
				dp[i][j][step] =   getDpValue(dp, i-2, j-1, step-1)
					+  getDpValue(dp, i-2, j+1, step-1)
					+  getDpValue(dp, i-1, j-2, step-1)
					+  getDpValue(dp, i-1, j+2, step-1)
					+  getDpValue(dp, i+1, j-2, step-1)
					+  getDpValue(dp, i+1, j+2, step-1)
					+  getDpValue(dp, i+2, j-1, step-1)
					+  getDpValue(dp, i+2, j+1, step-1);
			}
		}
	}		    
	return dp[x][y][k];
}


int main(){
	cout<<"暴力递归："<<horseJump(3,3,2)<<"\n";;
	cout<<"动态规划："<<horseJumpDP(3,3,2)<<"\n";
    return 0;
}