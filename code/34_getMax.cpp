#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>

//不用if比较语句，求max(a,b)
class GetMax{
public:
	// 请保证参数n，不是1就是0的情况下
	// 1 -> 0
	// 0 -> 1
	int flip(int n){
		return n^1;
	}
	// n是非负数，返回1
	// n是负数，返回0
	int sign(int n){
		return flip( (n>>31) & 1 );//符号位移到最右边 & 1
	}
	int getMax1(int a,int b){//不考虑c溢出的问题
		int c = a - b;
		int scA = sign(c);// a-b为非负，scA为1；a-b为负，scA为0
		int scB = flip(scA);// a-b为非负，scA为1；a-b为负，scA为0
		// scA为0，scb必为1；scA为1，scB必为0
		return a * scA + b * scB;
	}
	int getMax2(int a, int b) {
		int c = a - b;
		int sa = sign(a);
		int sb = sign(b);
		int sc = sign(c);
		int difSab = sa ^ sb;// a和b的符号不一样，为1；一样，为0
		int sameSab = flip(difSab); // a和b的符号一样，为1；不一样，为0
		int returnA = difSab * sa + sameSab * sc;
		int returnB = flip(returnA);
		return a * returnA + b * returnB;
	}

};


int main(){
	GetMax getMax;
    int a = -16;
	int b = 1;
	cout<<getMax.getMax1(a,b)<<"\n";
	cout<<getMax.getMax2(a,b)<<"\n";
	a = 2147483647;
	b = -2147480000;
	cout<<"c="<<a-b;
	cout<<"溢出,答案错误:"<<getMax.getMax1(a,b)<<"\n";
	cout<<getMax.getMax2(a,b)<<"\n";
    return 0;
}