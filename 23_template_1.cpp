#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
Template Method模式也叫模板方法模式，是行为模式之一，它把具有特定步骤算法中的某些必要的处理
 委让给抽象方法，通过子类继承对抽象方法的不同实现改变整个算法的行为。

 总结:在抽象类中统一操作步骤，并规定好接口；让子类实现接口。这样可以把各个具体的子类和操作步骤解耦合
*/

class MakeCar{
public:
    virtual void MakeHead() = 0;
    virtual void MakeBody() = 0;
    virtual void MakeTail() = 0;

public:
    void Make(){ //模板函数 把业务逻辑给做好
        MakeTail();
        MakeBody();
        MakeHead();
    }
};

class Jeep : public MakeCar{
public:
    virtual void MakeHead(){
        cout << "jeep head" << endl;
    }

    virtual void MakeBody(){
        cout << "jeep body" << endl;
    }

    virtual void MakeTail(){
        cout << "jeep tail" << endl;
    }
};

class Bus : public MakeCar{
public:
    virtual void MakeHead(){
        cout << "Bus head" << endl;
    }

    virtual void MakeBody(){
        cout << "Bus body" << endl;
    }

    virtual void MakeTail(){
        cout << "Bus tail" << endl;
    }
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}
void test_23_1()
{
    MakeCar *car = new Bus;
    car->Make();
    SAFE_DELETE(car);

    MakeCar *car2 = new Jeep;
    car2->Make();
    SAFE_DELETE(car2);
}

int main_231() {

    test_23_1();
    return 0;
}
