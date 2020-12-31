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
            vector<char>set;
            for(int i=0;i<str.size();i++){
                set.push_back(str[i]);
            }
            process(set, "", res);
            return res;
        }
        void process(vector<char>set, string path, vector<string>&res){
            if(set.empty()){
                res.push_back(path);
                return;
            }
            unordered_set<char>hash;
            for(int i=0;i<set.size();i++){
                if(hash.find(set[i])==hash.end()){
                    hash.insert(set[i])
                    ;
                    vector<char>next = set;
                    next.erase(next.begin()+i);
                    process(next, path+set[i], res);
                }               
            }
        }
};

int main(){
    Solution solu;
    vector<string>res = solu.getPermutation("aac");
    cout<<"全排列：";
    for(auto i:res){
        cout<<i<<",";
    }
    return 0;
}