#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//给定两个长度都为N的数组weights和values，weights[i]和values[i]分别代表 i号物品的重量和价值。
//给定一个正数bag，表示一个载重bag的袋子，你装的物品不能超过这个重量。返回你能装下最多的价值是多少？

class Solution{
    public:
		//===========暴力递归
        int getMaxValue(vector<int>w, vector<int>v, int bag) {
			return process(w, v, 0, bag);
		}

		// w[index] 当前货物的重量
		// v[index] 当前货物的价值
		// rest：在0..index-1已经做的决定之下，当前袋子还有多少空间
		// bag：袋子的总重量
		// index ....后续所有货物自由选择，返回最大的价值
		int process(vector<int>w, vector<int>v, int index, int rest) {
			if (rest < 0) {
				return -1;
			}
			// 重量没超
			if (index == w.size()) {
				return 0;
			}
			// 不要当前index的货物
			int p1 = process(w, v, index + 1, rest);
			// 要当前货物，p2next为后续得到的价值
			int p2next = process(w, v, index + 1, rest - w[index]);
			int p2 = -1;
			if (p2next != -1) {//若后续失效，则p2保持失效的初值
				p2 = v[index] + p2next;
			}
			return max(p1, p2);
		}
		//====================DP====================
		int getMaxValueDP(vector<int>w, vector<int>v, int bag) {
			int n = w.size();			
			vector<vector<int>>dp(n+1, vector<int>(bag+1));
			//dp[index][rest]表示w[index..]上选择，容纳最大重量为rest，可得到的最大价值。
			for(int index=n-1; index>=0; index--){
				for(int rest=0; rest<=bag; rest++){
					if(rest-w[index]<0){
						dp[index][rest] = dp[index+1][rest];//dp[n][rest]默认是0
					}
					else{
						dp[index][rest] = max(dp[index+1][rest], v[index] + dp[index+1][rest-w[index]]);
					}					
				}
			}
			return dp[0][bag];
		}
};

int main(){
    Solution solu;
    cout<<"最大价值："<<solu.getMaxValue({3,2,5},{2,3,3},7)<<"\n";
    cout<<"最大价值："<<solu.getMaxValue({30,20,50},{2,3,3},7)<<"\n";

	cout<<"最大价值："<<solu.getMaxValueDP({3,2,5},{2,3,3},7)<<"\n";
    cout<<"最大价值："<<solu.getMaxValueDP({30,20,50},{2,3,3},7);
    return 0;
}