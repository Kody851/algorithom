#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//贪心算法：只有一个会议室，有多个会议（8~11点，9~10点，10~12点），问可以安排的最大会议数量。

//思路：先安排结束时间早的会议
bool cmp2(pair<int,int>a, pair<int,int>b){//只能放class Solution外面
        return a.second < b.second;
}
class Solution{
public:
    
    /*class Program{
    public:
        int start;
        int end;
        Program(int s, int e){
            start = s;
            end = e;
        }
    };
    bool cmp1(Program a, Program b){
        return a.end < b.end;
    }*/
    
    int bestArrange(vector<pair<int,int>>time, int timePoint) {
        sort(time.begin(),time.end(),cmp2);
		int result = 0;
		// 从左往右依次遍历所有的会议
		for (int i = 0; i < time.size(); i++) {
			if (timePoint <= time[i].first) {
				result++;
				timePoint = time[i].second;
			}
		}
		return result;
	}
};

int main(){
    Solution solu;
    vector<pair<int,int>>time{{8,11},{9,10},{10,12}};
    cout<<"可安排会议数量="<<solu.bestArrange(time,0)<<endl;
    return 0;
}