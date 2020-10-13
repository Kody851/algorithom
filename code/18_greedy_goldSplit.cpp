#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//切金条问题：把金条切成数组元素的几个部分，所花代价最小（代价为当前金条总量）

//思路：把数组放入小根堆，一次弹出两个，合成一个点，把合成的点放入堆，依次。
bool cmp2(pair<int,int>a, pair<int,int>b){//只能放class Solution外面
        return a.second < b.second;
}
class Solution{
public:
    
    int goldSplit(vector<int>arr) {
        priority_queue<int,vector<int>,greater<int>> smallHeap;
        for(auto i:arr){
            smallHeap.push(i);
        }
        int sum = 0;
        while(smallHeap.size()>1){
            int x1 = smallHeap.top();
            smallHeap.pop();
            int x2 = smallHeap.top();
            smallHeap.pop();
            sum = sum+x1+x2;
            smallHeap.push(x1+x2);
        }
        return sum;
	}
};

int main(){
    Solution solu;
    vector<int>arr{10,20,30};
    cout<<"切金条最小代价："<<solu.goldSplit(arr)<<endl;
    return 0;
}