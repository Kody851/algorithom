#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//规定1和A对应、2和B对应、3和C对应...
//那么一个数字字符串比如"111"，就可以转化为"AAA"、"KA"和"AK"。
//给定一个只有数字字符组成的字符串str，返回有多少种转化结果。

class Solution{
    public:
        int numStrConvert(string str){
            if(str.empty() || str.size()==0) return 0;
            return process(str,0);
        }
        // i之前的位置，如何转化已经做过决定了, 不用再关心
	    // str[i..] 有多少种转化的结果
        int process(string str,  int i){
            if(i==str.size()){
                return 1;
            }
            if(str[i]=='0'){
                return 0;
            }
            if(str[i]=='1'){
                int res = process(str,i+1);//i作为单独的部分，后续有多少种方法
                if(i+1<str.size()){
                    res+=process(str,i+2);//（i和i+1）作为单独的部分，后续有多少种方法
                }
                return res;
            }
            if(str[i]=='2'){
                int res = process(str,i+1);
                if(i+1<str.size() && str[i+1]>='0' && str[i+1]<='6'){
                    res+=process(str,i+2);
                }
                return res;
            }
            //'3'~'9'
            return process(str,i+1);
        }
};

int main(){
    Solution solu;
    int res = solu.numStrConvert("127");
    cout<<"转化结果数量："<<res;
    return 0;
}