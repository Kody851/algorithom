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
        int getMaxValue(vector<int>w, vector<int>v, int bag) {
			return process(w, v, 0, 0, bag);
		}

		// w[index] 当前货物的重量
		// v[index] 当前货物的价值
		// alreadyW：0..index-1已经做的决定，所形成的目前重量
		// bag：袋子的总重量
		// index ....后续所有货物自由选择，返回最大的价值
		int process(vector<int>w, vector<int>v, int index, int alreadyW, int bag) {
			if (alreadyW > bag) {
				return -1;
			}
			// 重量没超
			if (index == w.size()) {
				return 0;
			}
			// 不要当前index的货物
			int p1 = process(w, v, index + 1, alreadyW, bag);
			// 要当前货物，p2next为后续得到的价值
			int p2next = process(w, v, index + 1, alreadyW + w[index], bag);
			int p2 = -1;
			if (p2next != -1) {//若后续失效，则p2保持失效的初值
				p2 = v[index] + p2next;
			}
			return max(p1, p2);
		}

};

int main(){
    Solution solu;
    cout<<"最大价值："<<solu.getMaxValue({3,2,5},{2,3,3},7)<<"\n";
    cout<<"最大价值："<<solu.getMaxValue({30,20,50},{2,3,3},7);
    return 0;
}