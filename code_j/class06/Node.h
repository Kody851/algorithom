class Edge;
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