#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//给一个图（有向无环），输出它的拓扑排序

class Solution{
    public:
        vector<int> topologySort(vector<pair<int, int>>&edge, vector<int>vexs){//给了节点数组
            //先找到入度为0的点，把它擦掉，把它相邻的边也擦掉，找下一个入度为0的点
            int num = vexs.size();
            vector<vector<int>> graph(num, vector<int>(0));//邻接表
            vector<int> inDegree(num, 0);//记录入度
            for(auto i:edge) {
                graph[i.first].push_back(i.second);
                inDegree[i.second]++;
            }      
            queue<int>q;
            // 入度为0的点，才能进这个队列
            for(int i=0;i<num;i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
            // 拓扑排序的结果，依次加入res
            vector<int>res;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                res.push_back(vexs[cur]);
                for(auto i:graph[cur]){
                    inDegree[i]--;
                    if(inDegree[i]==0){
                        q.push(i);
                    }
                }
            }
            return res;
        }
        
};

int main(){
    Solution solu;   
    vector<pair<int,int>>edge{{0,1},{0,2},{1,2},{1,5},{2,3},{2,4}};
    vector<int>vexs{0,1,2,3,4,5};
    for(auto i:edge){
        cout<<i.first<<","<<i.second<<"\n";
    }   
    for(auto i:vexs){
        cout<<i<<" ";
    }
    cout<<"\n topologySort: \n";
    
    for(auto i:solu.topologySort(edge,vexs)){
        cout<<i<<" ";
    }
   

	
    return 0;
}