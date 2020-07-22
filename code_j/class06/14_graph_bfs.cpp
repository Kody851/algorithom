#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//https://blog.csdn.net/xiqingnian/article/details/41214539 (C++中两个类互相引用的解决方法)
class Edge {   
    public:
        int weight;
        Node from;
        Node to;
        Edge(int weight, Node from, Node to):from(from),to(to) {
            weight = weight;
            from = from;
            to = to;
        }
};
class Node {
    public:
        int val;
        int in;
        int out;
        vector<Node> nexts;
        vector<Edge> edges;
	    Node(int val) {
            val = val;
            in = 0;
            out = 0;
            nexts = vector<Node>();
            edges = vector<Edge>();
	}
};
class Graph {
    public:
        unordered_map<int, Node> nodes;
        unordered_set<Edge> edges;
        Graph():edges(edges) {
            nodes = unordered_map<int, Node>();
            edges = edges;
        }
};

class Solution{
    public:
        Graph* createGraph(vector<vector<int>>matrix) {
		Graph* graph = new Graph();
		for (int i = 0; i < matrix.size(); i++) { // matrix[0][0], matrix[0][1]  matrix[0][2]
			int from = matrix[i][0];
			int to = matrix[i][1];
			int weight = matrix[i][2];
			if (!graph->nodes.count(from)) {
                graph->nodes[from] = *new Node(from);
			}
			if (!graph->nodes.count(to)) {
				graph->nodes[to] = *new Node(to);
			}
			Node fromNode = graph->nodes[from];
			Node toNode = graph->nodes[to];
			Edge *newEdge = new Edge(weight, fromNode, toNode);
			fromNode.nexts.push_back(toNode);
			fromNode.out++;
			toNode.in++;
			fromNode.edges.push_back(*newEdge);
			graph->edges.insert(*newEdge);
		}
		return graph;
	}
};

int main(){
    
    Solution solu;
    vector<int>a{1,2};
	vector<vector<int>> matrix{{1,2},{3,4}};
    cout<<matrix[0][1];

	
    return 0;
}