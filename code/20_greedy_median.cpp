#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//数据流的中位数


//思路：较小的N/2个数永远在大根堆里，较大的N/2个数永远在小根堆里。O(logn)
//     若大根堆为空，则进大根堆；
//若小于大根堆顶，则进大根堆；否则进小根堆；
//每次进来数，比较两个堆的size，若size不小于2，则把size大的堆顶弹出到size小的堆中；
//奇数个数，则中位数为size较大的堆的堆顶


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
    float median(vector<int>arr) {
        priority_queue<int, vector<int>, greater<int> > minheap;
        priority_queue<int, vector<int>, less<int> > maxheap;
        for(int i=0;i<arr.size();i++){
            if(maxheap.empty() || arr[i]<=maxheap.top()){
                maxheap.push(arr[i]);
            }
            else{
                minheap.push(arr[i]);
            }
            if(minheap.size() - maxheap.size() == 2){
                maxheap.push(minheap.top());
                minheap.pop();
            }
            if(maxheap.size() - minheap.size() == 2){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        if(minheap.size() + maxheap.size() == 0){
            return -1;
        }
        if(minheap.size() == maxheap.size()){
            return (minheap.top() + maxheap.top()) / 2.0;
        }
        else{
            return minheap.size() > maxheap.size() ? minheap.top() : maxheap.top();
        }
	}
};

int main(){
    Solution solu;

    vector<int>arr{2,5,3,1,4,6};
   
    cout<<"中位数："<<solu.median(arr)<<endl;
    return 0;
}