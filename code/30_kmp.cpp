#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>

//KMP算法
//
vector<int>getNextArray(string ms) {
	if (ms.size() == 1) {
		return vector<int>{-1};
	}
	vector<int> next(ms.size());
	next[0] = -1;
	next[1] = 0;
	int i = 2; //数组的位置
	int cn = 0;
	while (i < next.size()) {
		if (ms[i - 1] == ms[cn]) {
			next[i++] = ++cn;
		} 
		else if (cn > 0) { // 当前跳到cn位置的字符，和i-1位置的字符配不上
			cn = next[cn];
		} 
		else {
			next[i++] = 0;
		}
	}
	return next;
}
int getIndei1Of(string s, string m) {
	if (s.empty() || m.empty() || s.size() < m.size()) {
		return -1;
	}
	string str1 = s;
	string str2 = m;
	int i1 = 0;
	int i2 = 0;
	vector<int>next = getNextArray(str2); // O (M)
	// O(N)
	while  (i1 < str1.size() && i2 < str2.size()) {
		if (str1[i1] == str2[i2]) {
			i1++;
			i2++;
		} 
		else if (next[i2] == -1) { // str2中比对的位置已经无法往前跳了
			i1++;
		} 
		else {
			i2 = next[i2];
		}
	}
	// i1 越界  或者  i2越界了
	return i2 == str2.size() ? i1 - i2 : -1;
}


int main(){
    string str = "abcabcababaccc";
	string match = "ababa";
	cout<<getIndei1Of(str, match);
    return 0;
}