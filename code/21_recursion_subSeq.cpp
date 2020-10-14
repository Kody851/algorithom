#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//打印一个字符串的全部子序列，包括空字符串。
//例如：“abc”;  输出："","a","b","c","ab","ac","bc","abc".
class Solution{
    public:
        vector<string>getSubseq(string str){
            vector<string>res;
            if(str.empty()){
                return res;
            }
            if(str.size()==0){
                res.push_back("");
                return res;
            }
            process(str, 0, "", res);
            return res;
        }
        void process(string str, int index, string path, vector<string>&res){
            if(index == str.size()){//超出str范围，才把之前path(包含最后一个字符)加入。
                res.push_back(path);
            }
            else{
                process(str, index+1, path, res);
                process(str, index+1, path+str[index], res);
            }
        }
};

int main(){
    Solution solu;
    vector<string>res = solu.getSubseq("abc");
    cout<<"子序列：";
    for(auto i:res){
        cout<<i<<",";
    }
    return 0;
}