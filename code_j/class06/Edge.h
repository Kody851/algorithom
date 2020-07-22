class Node;
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