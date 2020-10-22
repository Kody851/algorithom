#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>

//设计一种结构，在该结构中有如下三个功能:
//insert(key):将某个key加入到该结构，做到不重复加入
//delete(key):将原本在结构中的某个key移除
//getRandom(): 等概率随机返回结构中的任何一个key。
//【要求】Insert、delete和getRandom方法的时间复杂度都是O(1)

class Pool{
    public:
        unordered_map<string,int> key_index;
        unordered_map<int,string> index_key;
        void insert(string key){
            if(!key_index.count(key)){
                key_index[key] = key_index.size();
                index_key[index_key.size()] = key;
            }
        }
        void delete_key(string key){
            if(key_index.count(key)){
                /*
                举例：
                "a" <-> 0
                "b" <-> 1
                "c" <-> 2
                */
                int deleteIndex = key_index[key];//1
                int lastIndex = key_index.size()-1;//2
                string lastKey = index_key[lastIndex];//"c"

                key_index[lastKey] = deleteIndex;//["c"]=1
                key_index.erase(key);//删掉"b"

                index_key[deleteIndex] = lastKey;//[1]="c"
                index_key.erase(2);//删掉2

            }
        }
        string getRandom(){
            if(key_index.size()==0){
                return NULL;
            }
            int randomIndex = rand() % key_index.size();// 0 ~ size -1
            return index_key[randomIndex];
            //return index_key[1];//"c"
        }
};
int main(){
    Pool pool;
    pool.insert("a");
    pool.insert("b");
    pool.insert("c");
    pool.delete_key("b");
    cout<<pool.getRandom()<<"\n";
    return 0;
}