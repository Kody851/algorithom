#include<queue>
#include<stack>
#include<algorithm>//max
#include<cmath>//abs
using namespace std;
/*
派对的最大快乐值员工信息的定义如下: 
class Employee { 
    public int happy; // 这名员工可以带来的快乐值 
    List<Employee> subordinates; // 这名员工有哪些直接下级 
}
公司的每个员工都符合 Employee 类的描述。整个公司的人员结构可以看作是一棵标准的、 没有环的多叉树。
树的头节点是公司唯一的老板。除老板之外的每个员工都有唯一的直接上级。 
叶节点是没有任何下属的基层员工(subordinates列表为空)，除基层员工外，每个员工都有一个或多个直接下级。 
这个公司现在要办party，你可以决定哪些员工来，哪些员工不来。但是要遵循如下规则。 
1.如果某个员工来了，那么这个员工的所有直接下级都不能来 
2.派对的整体快乐值是所有到场员工快乐值的累加 
3.你的目标是让派对的整体快乐值尽量大给定一棵多叉树的头节点boss，请返回派对的最大快乐值。
*/
class Node{
public:
    int happy;//快乐值
    vector<Node>next;//下级
    Node(int h, vector<Node>n){
        happy = h;
        next = n;
    }
};
class Info{
public:
    int headYes;//该节点来的最大快乐值
    int headNo;
    Info(int yes, int no){
        headYes = yes;
        headNo = no;
    }
};
Info* process(Node* x){
    if(x->next.empty()){//基层员工
        return new 
    }
}
int maxHappy(Node* head){

}

int main(){

    return 0;
}