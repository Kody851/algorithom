#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>

//头条面试题
//【题目】 一个矩阵中只有0和1两种值，每个位置都可以和自己的上、下、左、右 四个位置相连，
//如果有一片1连在一起，这个部分叫做一个岛，求一个矩阵中有多少个岛?

// 样本进来会包一层，叫做元素
//因为hash表是值传递的，同样的值认为相同，改成这样，引用传递，就可以处理相同值了（仍然可以是两个元素，可以属于两个集合）
class UnionFindSet{
public:
	unordered_map<string,string>fatherMap;
	unordered_map<string,int>sizeMap;
	void init(vector<string>list){
		for(auto i:list){
			fatherMap[i] = i;
			sizeMap[i] = 1;
		}
	}
	string findHead(string cur){
		vector<string>path;
		while(cur != fatherMap[cur]){
			path.push_back(cur);
			cur = fatherMap[cur];
		}
		for(auto i : path){
			fatherMap[i] = cur;
		}
		return cur;
	}
	bool isSameSet(string a, string b){
		if(fatherMap.count(a) && fatherMap.count(b) && findHead(a) == findHead(b)){
			return true;
		}
		return false;
	}
	void Union(string a, string b){
		if (!isSameSet(a,b) && fatherMap.count(a) && fatherMap.count(b)){
			string aHead = findHead(a);
			string bHead = findHead(b);
			string bigHead = sizeMap[aHead]>sizeMap[aHead] ? aHead : bHead;
			string smallHead = sizeMap[aHead]>sizeMap[aHead] ? bHead : aHead;
			fatherMap[smallHead] = bigHead;
			sizeMap[bigHead] = sizeMap[aHead] + sizeMap[bHead];
			sizeMap.erase(smallHead);
		}
		
	}
};
int countIslands(vector<vector<int>>m){
	if(m.empty()) return 0;
	vector<string>list;
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			if(m[i][j]==1){
				list.push_back(to_string(i) + "_" + to_string(j));
			}
		}
	}
	UnionFindSet unionFindSet;
	unionFindSet.init(list);
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			if(m[i][j]==1){
				string pos = to_string(i) + "_" + to_string(j);
				if(i-1>=0 && m[i-1][j]==1){
					string up = to_string(i-1) + "_" + to_string(j);
					unionFindSet.Union(pos, up);
				}
				if(j+1<m[0].size() && m[i][j+1]==1){
					string right = to_string(i) + "_" + to_string(j+1);
					unionFindSet.Union(pos, right);
				}
			}
		}
	}
	return unionFindSet.sizeMap.size();
}
int main(){
	vector<vector<int> > m1 = {  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
				        		 { 0, 1, 1, 1, 0, 1, 1, 1, 0 }, 
				        		 { 0, 1, 1, 1, 0, 0, 0, 1, 0 },
				        		 { 0, 1, 1, 0, 0, 0, 0, 0, 0 }, 
				        		 { 0, 0, 0, 0, 0, 1, 1, 0, 0 }, 
				        		 { 0, 0, 0, 0, 1, 1, 1, 0, 0 },
				        		 { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
	vector<vector<int> > m2 = {  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
								 { 0, 1, 1, 1, 1, 1, 1, 1, 0 }, 
								 { 0, 1, 1, 1, 0, 0, 0, 1, 0 },
								 { 0, 1, 1, 0, 0, 0, 1, 1, 0 }, 
								 { 0, 0, 0, 0, 0, 1, 1, 0, 0 }, 
								 { 0, 0, 0, 0, 1, 1, 1, 0, 0 },
								 { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
	cout<<countIslands(m1)<<"\n";
	cout<<countIslands(m2);
    return 0;
}