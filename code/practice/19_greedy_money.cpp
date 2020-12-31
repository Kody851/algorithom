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
    bool operator() (pair<int,int>a, pair<int,int>b){
        return a.first > b.first;
    }
};
struct cmp2{
    bool operator() (pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
    }
};
int maxprofit(vector<pair<int,int>>a, int k, int w){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> cost;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2> income;
    for(auto i:a){
        cost.push(i);
    }
    for(int i=0;i<k;i++){
        while(!cost.empty() && cost.top().first <= w){
            income.push(cost.top());
            cost.pop();
        }
        if(income.empty()){
            return w;
        }
        w += income.top().second;
        income.pop();
    }
    return w;

}

int main(){
    

    vector<pair<int,int>>item{{3,5},{7,1},{1,7},{6,9},{100,400}};
    int k=3,w=2;
   
    cout<<"最大利润："<<solu.maxProfit(item,k,w)<<endl;
    return 0;
}
vector<string>process(string str, int index, string path, vector<string>&res){
    if(index == str.size()){
        res.push_back(path);
        return res;
    }
    process(str, index+1, path, res);
    process(str, index+1, path+str[index], res);
    
}
vector<string>so(string str){
    vector<string>res;
    if(str.empty()) return res;
    if(str.size()==0){
        res.push_back("");
        return res;
    }
    return process(str, 0, "", res);
}