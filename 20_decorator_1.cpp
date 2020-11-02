#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
 必须 掌握 -->  代理模式, 装饰器模式, 适配器模式, 桥接模式 这4种结构型模式必须掌握
装饰者模式（Decorator Pattern）动态的给一个对象添加一些额外的职责。就增加功能来说，此模式比生成子类更为灵活。
*/

class Car{
public:
    virtual void show() = 0;
};

class RunCar : public Car{
public:
    virtual void show(){
        cout << "可以跑" << endl;
    }
};

class SwimCarDirector : public Car{
public:
    SwimCarDirector(Car *car){
        m_car = car;
    }
    void swim(){
        cout << "可以游" << endl;
    }
    virtual void show(){
        m_car->show();
        swim();
    }
    Car *m_car;
};

class  FlyCarDirector : public Car{
public:
    FlyCarDirector(Car *car){
        m_car = car;
    }
    void fly(){
        cout << "可以飞" << endl;
    }
    virtual void show(){
        m_car->show();
        fly();
    }
private:
    Car *m_car;
};

void test_20_1(){
    Car * mycar = NULL;
    mycar = new RunCar;
//    printf("-----000\n");
//    mycar->show();

//    printf("-----aaa\n");

    FlyCarDirector *flycar = new FlyCarDirector(mycar);
//    flycar->show();

    printf("-----bbb\n");
    SwimCarDirector *swimcar = new SwimCarDirector(flycar);
    swimcar->show();

    delete swimcar;
    delete flycar;
    delete mycar;
}

int main_20_1() {

    test_20_1();
    return 0;
}
