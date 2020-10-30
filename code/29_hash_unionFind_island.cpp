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
class Element {
	public:
        string value;
		Element(string v) {
			value = v;
		}
};
class UnionFindSet{
    public:
        unordered_map<string, Element*> elementMap;
		// key  某个元素  value 该元素的父
		unordered_map<Element*, Element*> fatherMap;
		// key 某个集合的代表元素   value 该集合的大小
		unordered_map<Element*, int> sizeMap;

		void init(vector<string> list) {
			for (string value : list) {
				Element* element = new Element(value);
				elementMap[value] = element;
				fatherMap[element] = element;//初始每个点指向自己
				sizeMap[element] = 1;
			}
		}
        // 给定一个element，往上一直找，把代表元素返回
		Element* findHead(Element* element) {
			stack<Element*> path;
			while (element != fatherMap[element]) {
				path.push(element);
				element = fatherMap[element];
			}
			//沿途各点的父改到代表元素，此步是为了降低时间复杂度
			while (!path.empty()) {
				fatherMap[path.top()] = element;
                path.pop();
			}
			return element;
		}
        bool isSameSet(string a, string b) {
			if (elementMap.count(a) && elementMap.count(b)) {
				return findHead(elementMap[a]) == findHead(elementMap[b]);
			}
			return false;
		}
        void Union(string a, string b) {
			if (elementMap.count(a) && elementMap.count(b)) {
				Element* aF = findHead(elementMap[a]);
				Element* bF = findHead(elementMap[b]);
				if (aF != bF) {
					Element* big = sizeMap[aF] >= sizeMap[bF] ? aF : bF;
					Element* small = big == aF ? bF : aF;
					fatherMap[small] = big;
					sizeMap[big] = sizeMap[aF] + sizeMap[bF];
					sizeMap.erase(small);
				}
			}
		}
};

int countIslands(vector<vector<int> >m){
	vector<string>list;
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			if(m[i][j]==1){
				string pos = to_string(i) + "_" + to_string(j);//atoi("1")
				list.push_back(pos);
			}
		}
	}
	UnionFindSet unionFindSet;
	unionFindSet.init(list);//初始化每个1都是孤立的岛
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			if(m[i][j]==1){
				string pos = to_string(i) + "_" + to_string(j);
				if(i-1>=0 && m[i-1][j]==1){
					string up = to_string(i-1) + "_" + to_string(j);
					unionFindSet.Union(up,pos);
				}
				if(j+1<m[0].size() && m[i][j+1]==1){
					string right = to_string(i) + "_" + to_string(j+1);
					unionFindSet.Union(right,pos);
				}
			}
		}
	}
	return unionFindSet.sizeMap.size();//unionFindSet.sizeMap里还存了每个岛屿1的个数
	
}
int main(){
    UnionFindSet unionFindSet;
    vector<string>list{"a","b","c"};
    unionFindSet.init(list);

    cout<<"elementMap:\n";
    unordered_map<string, Element*>::iterator iter;
    for(iter=unionFindSet.elementMap.begin();iter!=unionFindSet.elementMap.end();iter++){
        cout<<iter->first<<"->";
        cout<<iter->second->value<<"\n";
    }
    //cout<<unionFindSet.elementMap["a"]->value;
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