#include<iostream>
#include<queue>
#include<vector>
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
    vector<Node*>nexts;//下级
    Node(int h, vector<Node*>n){
        happy = h;
        nexts = n;
    }
};
class Info{
public:
    int headYes;//该节点来,整棵树的最大快乐值
    int headNo;//该节点不来，整棵树的最大快乐值
    Info(int yes, int no){
        headYes = yes;
        headNo = no;
    }
};
Info* process(Node* x){//以x为老板，能获得的最大快乐值
    if(x->nexts.empty()){//基层员工
        return new Info(x->happy,0);
    }
    int headYes = x->happy;
    int headNo = 0;
    for(auto next : x->nexts){//x的直接下属
        Info* nextInfo = process(next);
        headYes += nextInfo->headNo;//x来，下级不来
        headNo += max(nextInfo->headNo,nextInfo->headYes);//x来，下级爱来不来
    }
    return new Info(headYes,headNo);
}
int maxHappy(Node* head){
    if(!head) return 0;
    return max(process(head)->headYes,process(head)->headNo);
}

int main(){
    
    Node* head = new Node(9,vector<Node*>{
        new Node(13,vector<Node*>{new Node(1,vector<Node*>()), new Node(2,vector<Node*>())}),
        new Node(2,vector<Node*>{new Node(10,vector<Node*>())})
    });
    /*
            9 
       13       2
    1      2       10
    */
    cout<<maxHappy(head);//(13+10)
    return 0;
    //考点：树形dp
}