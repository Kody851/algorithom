#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//N皇后问题是指在N*N的棋盘上要摆N个皇后，要求任何两个皇后不同行、不同列， 也不在同一条斜线上。 
//给定一个整数n，返回n皇后的摆法有多少种。 

//n=1，返回1。 n=2或3，2皇后和3皇后问题无论怎么摆都不行，返回0。 n=8，返回92。

class Solution{
    public:
        int num(int n) {
			if (n < 1) {
				return 0;
			}
			// record[0] ?  record[1]  ?  record[2]
			vector<int>record(n); // record[i] -> i行的皇后，放在了第几列
			return process(0, record, n);
		}

		// 潜台词：record[0..i-1]的皇后，任何两个皇后一定都不共行、不共列，不共斜线
		// 目前来到了第i行
		// record[0..i-1]表示之前的行，放了的皇后位置
		// n代表整体一共有多少行
		// 返回值是，摆完所有的皇后，合理的摆法有多少种
		int process(int i, vector<int>record, int n) {
			if (i == n) { // 终止行
				return 1;
			}
			int res = 0;
			for (int j = 0; j < n; j++) { // 当前行在i行，尝试i行所有的列  -> j
				// 当前i行的皇后，放在j列，会不会和之前(0..i-1)的皇后，不共行共列或者共斜线，
				// 如果是，认为有效
				// 如果不是，认为无效
				if (isValid(record, i, j)) {
					record[i] = j;
					res += process(i + 1, record, n);
				}
			}
			return res;
		}

		// record[0..i-1]你需要看，record[i...]不需要看
		// 返回i行皇后，放在了j列，是否有效
		bool isValid(vector<int>record, int i, int j) {
			for (int k = 0; k < i; k++) { // 之前的某个k行的皇后
				if (j == record[k] || abs(record[k] - j) == abs(i - k)) {
					return false;
				}
			}
			return true;
		}

};

int main(){
    Solution solu;
	int n=8;
    cout<<n<<"皇后的摆法："<<solu.num(n);
    return 0;
}