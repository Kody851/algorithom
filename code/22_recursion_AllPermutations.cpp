#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;

//打印一个字符串的全部排列，要求不要出现重复的排列

class Solution{
    public:
        vector<string>getPermutation(string str){
            vector<string>res;
            if(str.empty()){
                return res;
            }
            vector<char>available;
            for(int i=0;i<str.size();i++){
                available.push_back(str[i]);
            }
            process(available, "", res);
            return res;
        }
        //从左往右的尝试模型
        //available中的所有字符都可以选择
        //形成的所有排列(即沿途的决定path)放入res
        void process(vector<char>available,  string path, vector<string>&res){
            if(available.empty()){
                res.push_back(path);
                return;
            }
            unordered_set<char> picks;//当前已经挑过的字符
            //available中每个字符都可以作为当前字符，一旦选择，后续不能再用
            for (int index = 0; index < available.size(); index++) {
                if (picks.find(available[index])==picks.end()) {//去重
                    picks.insert(available[index]);
                    vector<char>next=available;
                    next.erase(next.begin() + index);
                    process(next, path+available[index], res);
                }
            }               
        }
};

int main(){
    Solution solu;
    vector<string>res = solu.getPermutation("abc");
    cout<<"全排列：";
    for(auto i:res){
        cout<<i<<",";
    }
    return 0;
}