#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//切金条问题：把金条切成数组元素的几个部分，所花代价最小（代价为当前金条总量）
/*
一块金条切成两半，是需要花费和长度数值一样的铜板的。
比如长度为20的金条，不管切成长度多大的两半，都要花费20个铜板。 
一群人想整分整块金条，怎么分最省铜板? 
例如,给定数组{10,20,30}，代表一共三个人，整块金条长度为10+20+30=60。 金条要分成10,20,30三个部分。 
如果先把长度60的金条分成10和50，花费60； 再把长度50的金条分成20和30，花费50；一共花费110铜板。 
但是如果先把长度60的金条分成30和30，花费60；再把长度30金条分成10和20， 花费30；一共花费90铜板。 
输入一个数组，返回分割的最小代价。
*/
//思路：把数组放入小根堆，一次弹出两个，合成一个点，把合成的点放入堆，依次。
//原理：哈夫曼编码问题
//把数组元素放入小根堆，每次取最小的两个，加和后放回去。这就是切金条的逆过程。
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