#include <iostream>
#include <string>
#include <stdio.h>
/*
代理模式：为其他对象提供一种代理以控制对这个对象的访问。
Subject：定义RealSubject和Proxy的共用接口，这样就可以在任何使用RealSubject的地方都可以使用Proxy。
RealSubject：真实处理业务的角色。
Proxy：保存一个引用使得代理可以访问实体。
*/
using namespace std;

//代理模式举例: 小明最近刚参加工作，想在单位附近租一间房子，但是对新环境又不熟悉，所以他想找一个房产中介来帮他租房。

//Subject
class Person{
public:
    virtual void rentHouse() = 0;
};

//RealSubject
class XiaoM :public Person{
public:
    void rentHouse(){
        cout << "小明需要租一间房子！" << endl;
    }
};

//Proxy
class Intermediary :public Person{
public:
    Intermediary(Person *person) :m_Person(person){} // 列表式构造方法
    void rentHouse(){
        m_Person->rentHouse();
        cout << "中介抽取佣金百分之6 " << endl;
    }
private:
    Person *m_Person;
};

void test_19_2(){
    //小明
    Person *xiaoM = new XiaoM; // 多态
    //找一个中介帮忙租房子
    Person *intermediary  = new Intermediary(xiaoM); // 多态

    intermediary->rentHouse(); // 指针, 不能用点
}


int main19_2() {

    test_19_2();
    return 0;
}
