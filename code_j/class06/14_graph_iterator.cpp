#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//https://github.com/Kody851/Get-offer/blob/master/leetcode%20207.cpp
class Solution{
    public:
        void graphBfsTable(vector<pair<int, int>>&edge, vector<int>vexs){//给了节点数组
            int num = vexs.size();
            vector<vector<int>> graph(num, vector<int>(0));//邻接表
            for(auto i:edge) graph[i.first].push_back(i.second);
            queue<int>q;
            unordered_set<int>visited;
            for(int i=0;i<num;i++){
                if(visited.find(i) == visited.end()){//防止重复入队列
                    visited.insert(i);
                    q.push(i);
                    while(!q.empty()){
                        int cur = q.front();
                        q.pop();
                        cout<<vexs[cur];//pop之后打印
                        for(auto j : graph[cur]){
                            if(visited.find(j) == visited.end()){
                                visited.insert(j);
                                q.push(j);
                            }
                        }
                    }
                }
            }
        }
        void graphBfsMatrix(vector<vector<int>>& edge, vector<int>vexs){//给了节点数组
            int num = vexs.size();
            vector<vector<int>>mat(num, vector<int>(num,0));//邻接矩阵
            for(int i=0;i<num;i++){
                for(int j=0;j<num;j++){
                    mat[edge[i][0]][edge[i][1]]=1;//x->y存在有向边，则为1
                }
            }
            queue<int>q;
            unordered_set<int>visited;
            for(int i=0;i<num;i++){
                if(visited.find(i) == visited.end()){//防止重复入队列
                    visited.insert(i);
                    q.push(i);
                    while(!q.empty()){
                        int cur = q.front();
                        q.pop();
                        cout<<vexs[cur];//pop之后打印
                        for(int j=0;j<num;j++){
                            if(visited.find(j)==visited.end() && mat[i][j]==1){
                                visited.insert(j);
                                q.push(j);
                            }
                        }
                    }
                }
            }
        }
        
        void graphDfsTable(vector<pair<int, int>>&edge, vector<int>vexs){//给了节点数组
            int num = vexs.size();
            vector<vector<int>> graph(num, vector<int>(0));//邻接表
            for(auto i:edge) graph[i.first].push_back(i.second);
            stack<int>stk;
            unordered_set<int>visited;
            for(int i=0;i<num;i++){
                if(visited.find(i) == visited.end()){//防止重复入栈
                    visited.insert(i);
                    stk.push(i);
                    cout<<vexs[i];//入栈就打印
                    while(!stk.empty()){
                        int cur = stk.top();
                        stk.pop();                       
                        for(auto j : graph[cur]){
                            if(visited.find(j) == visited.end()){
                                visited.insert(j);
                                stk.push(cur);//先把当前值压入栈
                                stk.push(j);
                                cout<<vexs[j];
                                break;//有新打印的节点就要break;cur的其他邻居待之后处理
                            }
                        }
                    }
                }
            }
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
    cout<<"\n BFS: \n";
    //solu.graphBfsTable(edge,vexs);
    cout<<"\n DFS: \n";
    solu.graphDfsTable(edge,vexs);
    //vector<int>a{1,2};
	//vector<vector<int>> matrix{{1,2},{3,4}};

	
    return 0;
}