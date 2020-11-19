#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_set>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//给定一个整型数组arr，代表数值不同的纸牌排成一条线。玩家A和玩家B依次拿走每张纸牌，规定玩家A先拿，玩家B后拿，
//但是每个玩家每次只能拿走最左或最右的纸牌，玩家A 和玩家B都绝顶聪明。请返回最后获胜者的分数。 

//【举例】 arr=[1,2,100,4]。 开始时，玩家A只能拿走1或4。如果开始时玩家A拿走1，则排列变为[2,100,4]，
//接下来 玩家 B可以拿走2或4，然后继续轮到玩家A... 如果开始时玩家A拿走4，则排列变为[1,2,100]，
//接下来玩家B可以拿走1或100，然后继 续轮到玩家A... 玩家A作为绝顶聪明的人不会先拿4，因为拿4之后，玩家B将拿走100。
//所以玩家A会先拿1， 让排列变为[2,100,4]，接下来玩家B不管怎么选，100都会被玩家 A拿走。玩家A会获胜， 分数为101。所以返回101。

class Solution{
public:
	int win(vector<int>arr) {
		if (arr.empty()) {
			return 0;
		}
		return max(f(arr, 0, arr.size() - 1), s(arr, 0, arr.size() - 1));
	}
    //先手的最大得分
	int f(vector<int>arr, int i, int j) {//[i..j]上，先手的最大得分
		if (i == j) {
			return arr[i];
		}
		return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
	}
    //后手的最大得分
	int s(vector<int>arr, int i, int j) {
		if (i == j) {
			return 0;//只剩一个时，后手是拿不到的
		}
		return min(f(arr, i + 1, j), f(arr, i, j - 1));//先手拿i或者j，他的考虑是让后手的得分最小。此步的决定权在先手。
	}

	//DP
	int winDP(vector<int>arr) {
		if (arr.empty()) {
			return 0;
		}
		int n = arr.size();
		//dpF[i][j]:  arr[i..j]上，先手的最大得分；
		//dpS[i][j]:  arr[i..j]上，后手的最大得分
		//vector<vector<int>> dpF(n, vector<int>(n));
		//vector<vector<int>> dpS(n, vector<int>(n));
		int dpF[n][n]; //= {{}};
		int dpS[n][n]; //= {{}};
		//i时的值与i+1有关，因此i从大到小遍历，另外i<=j;
		//j时的值与j-1有关，因此j从小到大遍历
		for(int j=0; j<n; j++){
			for(int i=j; i>=0; i--){
				if(i==j){
					dpF[i][j] = arr[i];
					dpS[i][j] = 0;
				}
				if(i+1<n)
					dpF[i][j] = max(arr[i]+dpS[i+1][j], arr[j]+dpS[i][j-1]);
				dpS[i][j] = min(dpF[i+1][j], dpF[i][j-1]);
			}
		}
		return max(dpF[0][n-1], dpS[0][n-1]);
	}

};

int main(){
    Solution solu;
    cout<<"获胜分数："<<solu.win({1,2,100,4})<<"\n";
	cout<<"DP获胜分数："<<solu.winDP({1,2,100,4})<<"\n";
    return 0;
}