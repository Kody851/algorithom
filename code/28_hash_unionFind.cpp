#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>

//并查集的实现
//对于若干集合，实现isSameSet和union两个函数，且要O(1)

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
				fatherMap[element] = element;
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
    return 0;
}