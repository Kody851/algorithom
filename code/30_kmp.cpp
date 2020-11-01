#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>

//KMP算法
//字符串匹配问题
//字符串str1和str2，str1是否包含str2，如果包含返回str2在str1中开始的位置。不包含返回-1。 
//如何做到时间复杂度O(N)完成？
vector<int>getNextArray(string ms) {
	if (ms.size() == 1) {
		return vector<int>{-1};
	}
	vector<int> next(ms.size());
	next[0] = -1;
	next[1] = 0;
	int i = 2; //数组的位置
	int cn = 0;//cn=next[i-1]
	while (i < next.size()) {// O(N)
		if (ms[i - 1] == ms[cn]) {
			next[i++] = ++cn;
		} 
		else if (cn > 0) { // 当前跳到cn位置的字符，和i-1位置的字符配不上
			cn = next[cn];
		} 
		else {
			next[i++] = 0;//跳转到开头也没找到ms[i - 1] == ms[cn]的情况，那么i位置的next取0
		}
	}
	return next;
}
int getIndexOf(string s, string m) {
	if (s.empty() || m.empty() || s.size() < m.size()) {
		return -1;
	}
	string str1 = s;
	string str2 = m;
	int i1 = 0;
	int i2 = 0;
	vector<int>next = getNextArray(str2); // O (M)
	// O(N)
	//str1从i位置与str2的0位置开始配，当str1到x，str2到y时，不匹配了。
	//这时，y回退到该元素的(最长前缀与最长后缀的)最大匹配长度坐标处，与x继续匹配
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
	//while循环停止意味着有字符串越界了
	// i1 越界  或者  i2越界了
	return i2 == str2.size() ? i1 - i2 : -1;
}


int main(){
    string str = "abcabcababaccc";
	string match = "ababa";
	cout<<getIndexOf(str, match);
    return 0;
}