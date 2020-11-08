#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>
//判断一个32位正数是不是2的幂、4的幂

bool is2Power(int n) {
	//2的幂：二进制中只有一位是1
	//常用技巧，只要最右边的1:   n & (~n + 1)  
	//return (n & (~n + 1))  == n
		return (n & (n - 1)) == 0;
}

bool is4Power(int n) {
	//4的幂：二进制中只有一位是1，且它是000001、000000100、000010000
	//16进制中的010101.....010101为0x55555555(32位除以4=8位，每个5代表一个0101)
	return (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
}




int main(){
	int n=8;
	cout<<(n & (~n + 1))<<"\n";
	cout<<(n & (n - 1));
    return 0;
}