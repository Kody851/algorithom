#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
/*
【题目】 有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置。 
例如，数组为[4,3,5,4,3,3,6,7]，窗口大小为3时: 
[4 3 5]4 3 3 6 7 
4[3 5 4]3 3 6 7 
4 3[5 4 3]3 6 7 
4 3 5[4 3 3]6 7 
4 3 5 4[3 3 6]7 
4 3 5 4 3[3 6 7]  
如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。 
请实现一个函数。 输入:整型数组arr，窗口大小为w。 
输出:一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值 
以本题为例，结果应该 返回{5,5,5,4,6,7}。
*/
void printVector(vector<int>arr){
	int i=0;
	for(;i<arr.size()-1;i++){
		cout<<arr[i]<<",";
	}
	cout<<arr[i];
}
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>res;
        if(num.empty()||size<=0||size>num.size()) return res;
        deque<int>dq;//双端队列，存储的是index
        for(unsigned int i=0;i<size;i++){
            while(!dq.empty()&&num[i]>num[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for(unsigned int i=size;i<num.size();i++){
            res.push_back(num[dq.front()]);
			//从队列后边操作，i处的值大于dq最后的值，就要从后边弹出
            while(!dq.empty()&&num[i]>num[dq.back()])
                dq.pop_back();
			dq.push_back(i);
			//最左边的数过期了，要去掉
            if(!dq.empty()&&(i-dq.front()>=size))
               dq.pop_front();   
        }
        res.push_back(num[dq.front()]);
        return res;
    }
//更一般的，我们可以实现更广泛的情况：滑窗大小可以不固定，而是任意变化。
//L和R都随意往右移动，只满足L不要跑到R右边即可。
class WindowMax{
public:
	int L;
	int R;
	vector<int>arr;
	deque<int>dq;
	//R右移
	void addNumFromRight() {
		if(R == arr.size()) {
			return;
		}
		while (!dq.empty() && arr[dq.back()] <= arr[R]) {
			dq.pop_back();
		}
		dq.push_back(R);
		R++;
	}
	//L右移
	void removeNumFromLeft() {
		if(L >= R-1) {
			return;
		}
		L++;
		if(dq.front() == L) {
			dq.pop_front();
		}
	}
	//任意时刻，当前的最大值
	int getMax() {
		if(!dq.empty()) {
			return arr[dq.front()];
		}
		return -1;
	}
};
////////////////////////
int main(){
	printVector(maxInWindows({ 4, 3, 5, 4, 3, 3, 6, 7 }, 3));
    return 0;
}