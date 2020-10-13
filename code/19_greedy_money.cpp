#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//赚钱的项目问题
//几个项目的成本和净利润如下，你只能串行做k个项目，启动资金为w，问最多挣多少钱？

//思路：把花费放入小根堆，利润放入大根堆（初始为空）;
//     把小根堆中满足启动资金的弹出压到大根堆，把大根堆中利润最大的项目做了，做完弹出并更新启动资金。


struct cmp1{
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.first > b.first;
    }
};
//https://www.cnblogs.com/huashanqingzhu/p/11040390.html
//https://www.cnblogs.com/fzuljz/p/6171963.html
struct cmp2 {
    bool operator() (pair<int,int>a, pair<int,int>b) {
        return a.second < b.second;
    }
};

class Solution{
public:   
    int maxProfit(vector<pair<int,int>>item, int k, int w) {
        priority_queue<pair<int,int>, vector<pair<int,int> >, cmp1> minCost;
        priority_queue<pair<int,int>, vector<pair<int,int> >, cmp2> maxIncome;
        for(auto i:item){
            minCost.push(i);
        }
        for(int i=0;i<k;i++){
            while(!minCost.empty() && minCost.top().first<=w){
                maxIncome.push(minCost.top());
                minCost.pop();
            }
            if(maxIncome.empty()){
                return w;
            }
            w += maxIncome.top().second;
            maxIncome.pop();
        }
        return w;
	}
};

int main(){
    Solution solu;

    vector<pair<int,int>>item{{3,5},{7,1},{1,7},{6,9},{100,400}};
    int k=3,w=2;
   
    cout<<"最大利润："<<solu.maxProfit(item,k,w)<<endl;
    return 0;
}