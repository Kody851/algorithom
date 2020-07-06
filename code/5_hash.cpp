 /*
 C++ 11中出现了两种新的关联容器:unordered_set和unordered_map，其内部实现与set和map大有不同，
 set和map内部实现是基于RB-Tree，而unordered_set和unordered_map内部实现是基于哈希表(hashtable)
 */
#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>


int main(){
    cout<<"=======unordered_set=============\n";
    unordered_set<int> hashset;
    if(hashset.find(0)==hashset.end());//这表明hashset中没有元素i
        hashset.insert(0); //插入元素i
    hashset.insert(1);
    hashset.erase(1);
    cout<<"set:"<<hashset.count(0)<<"\n";//1：存在；0：不存在

    cout<<"=======unordered_map=============\n";
    unordered_map<string,int> hashmap;//等同于hashmap(0)
    hashmap["a"]=1;
    hashmap.insert(make_pair("b",2));
    cout<<"map "<<hashmap["a"]<<" "<<hashmap["b"]<<" "<<hashmap["c"]<<"\n";//hashmap["c"]会初始化为0
    cout<<hashmap.count("a")<<" "<<hashmap.count("d")<<"\n";
    hashmap.erase("a");
    cout<<hashmap.count("a")<<"\n";

    cout<<"=======map=============\n";
    //https://www.cnblogs.com/shona/p/11281971.html
    map<string,int> dict;
    if(dict.empty())
        cout<<"该字典无元素"<<endl;
    else
        cout<<"该字典共有"<<dict.size()<<"个元素"<<endl;
    // 插入数据的三种方式
    dict.insert(pair<string,int>("apple",2));
    dict.insert(map<string, int>::value_type("orange",3));
    dict["banana"] = 6;
    // 遍历
    map<string, int>::iterator iter;
    for(iter=dict.begin();iter!=dict.end();iter++)
        cout<<iter->first<<ends<<iter->second<<endl;
  
    // 查找
    if((iter=dict.find("banana"))!=dict.end()) //  返回一个迭代器指向键值为key的元素，如果没找到就返回end()
        cout<<"已找到banana,其value为"<<iter->second<<"."<<endl;
    else
        cout<<"未找到banana."<<endl;
  
    if(dict.count("watermelon")==0) // 返回键值等于key的元素的个数
        cout<<"watermelon不存在"<<endl;
    else
        cout<<"watermelon存在"<<endl;
     
    pair<map<string, int>::iterator, map<string, int>::iterator> ret;
    ret = dict.equal_range("banana"); // 查找键值等于 key 的元素区间为[start,end)，指示范围的两个迭代器以 pair 返回
    cout<<ret.first->first<<ends<<ret.first->second<<endl;
    cout<<ret.second->first<<ends<<ret.second->second<<endl;
  
    iter = dict.lower_bound("boluo"); // 返回一个迭代器，指向键值>=key的第一个元素。
    cout<<iter->first<<endl;
    iter = dict.upper_bound("boluo"); // 返回一个迭代器，指向值键值>key的第一个元素。
    cout<<iter->first<<endl;
    return 0;
}