#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//打印n层汉诺塔（只能小数在上，大数在下）从最左边移动到最右边的全部过程。中间有个过渡塔。
//技巧：参数抽象化（最普通的暴力递归）
class Solution{
    public:
        void hanoi(int n){
            if(n>0){
                func(n, "左", "右", "中");
            }
        }
        void func(int N, string from, string to, string other){
            if(N==1){
                cout<<"Move 1 from " + from + " to " + to + "\n";
            }
            else{
                func(N-1, from, other, to);
                cout<<"Move " << N << " from " + from + " to " + to + "\n";
                func(N-1, other, to, from);
            }
        }
};

int main(){
    Solution solu;
    solu.hanoi(3);
    return 0;
}