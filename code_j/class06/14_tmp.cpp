
//避免问题：类xx不存在默认构造函数
class Thing {
public:
    int num;
    Thing(int num) {
        this->num = num;
    }
};

class Stuff {
public:
    Thing thing;  // an instance of thing is declared here but it cannot construct it
    /*Stuff(Thing thing) {//这样会出错
        this->thing = thing;
    }*/
    Stuff(Thing thing) : thing(thing) {
    // Nothing left to do.
    }
};

int main() {
    Thing thing = Thing(5);
    Stuff stuff = Stuff(thing);
}