#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//最小生成树算法-Prim

class Solution{
    public:
        vector<int> graphBfsMatrix(vector<vector<int>>& edge, vector<int>vexs){//给了节点数组
            //edge:[x,y,distance] x->y
            vector<int>res;
            int num = vexs.size();
            vector<vector<int>>mat(num, vector<int>(num,-1));//默认无连接，权重用-1表示
            for(int i=0;i<num;i++){
                mat[i][i] = 0;//点本身权重为0
                mat[edge[i][0]][edge[i][1]]=edge[i][2];//x->y存在有向边distance
            }
            
            priority_queue<int, vector<int>, greater<int> > heap;// 小顶堆
            unordered_set<int>visited;
            for(int i=0;i<num;i++){//任选一个点出发
                if(visited.find(i)==visited.end()){
                    visited.insert(i);
                    for(int j=0;j<num;j++){//将i点连接的边加入小根堆
                        if(mat[i][j]!=-1 && mat[i][j]!=0){
                            heap.push(mat[i][j]);
                        }
                    }
                    while(!heap.empty()){
                        int minEdge = heap.top();
                        heap.pop();//弹出最小的边
                        int toNode;
                        for(int j=0;j<num;j++){//找到该边指向的节点toNode
                            for(int k=0;k<num;k++){
                                if(mat[j][k]==minEdge){
                                    toNode = k;
                                }
                            }
                        }
                        if(visited.find(toNode)==visited.end()){//如果toNode是新节点
                            visited.insert(toNode);
                            res.push_back(minEdge);//边放入结果
                            for(int j=0;j<num;j++){//toNode相连的边放入小根堆
                                if(mat[toNode][j]!=-1 && mat[toNode][j]!=0){
                                    heap.push(mat[toNode][j]);
                                }
                            }
                        }
                    }
                }
            }
            return res;
        }
      
};

int main(){
    Solution solu;
    
    vector<pair<int,int>>pedge{{0,1},{0,2},{1,2},{1,5},{2,3},{2,4}};
    vector<int>vexs{0,1,2,3,4,5};
    for(auto i:pedge){
        cout<<i.first<<","<<i.second<<"\n";
    }   
    for(auto i:vexs){
        cout<<i<<" ";
    }
    vector<vector<int>>edge{{0,1,1},{0,2,3},{1,2,1},{1,5,4},{2,3,3},{2,4,6}};
    vector<int>res = solu.graphBfsMatrix(edge,vexs);
    cout<<"\n最小生成树:\n";
    for(auto i:res)
        cout<<i<<",";
	
    return 0;
}