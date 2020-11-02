#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
Mediator模式中，类之间的交互行为被统一放在Mediator的对象中，对象通过Mediator对象同其他对象交互，Mediator对象起着控制器的作用。
*/

class Person{
public:
    Person(string name, int sex, int condi){
        m_name = name;
        m_sex = sex;
        m_condi = condi;
    }
    string getName(){
        return m_name;
    }
    int getSex(){
        return m_sex;
    }
    int getCondi(){
        return m_condi;
    }
    virtual void getParter(Person *p) = 0;

protected:
    string	m_name;
    int		m_sex;
    int		m_condi;
};


class Woman : public Person{
public:
    Woman(string name, int sex, int condi) : Person(name, sex, condi){}

    virtual void getParter(Person *p){
        if (this->m_sex == p->getSex()){
            cout << "我不是同性恋..." << endl;
        }
        if (this->getCondi() == p->getCondi() ){
            cout << this->getName() << " 和 " << p->getName() << "绝配 " <<endl;
        }
        else{
            cout << this->getName() << " 和 " << p->getName() << "不配 " <<endl;
        }
    }
};


class Man : public Person{
public:
    Man(string name, int sex, int condi) : Person(name, sex, condi){}

    virtual void getParter(Person *p){
        if (this->m_sex == p->getSex()){
            cout << "我不是同性恋..." << endl;
        }
        if (this->getCondi() == p->getCondi() ){
            cout << this->getName() << " 和 " << p->getName() << "绝配 " <<endl;
        }
        else{
            cout << this->getName() << " 和 " << p->getName() << "不配 " <<endl;
        }
    }
};
#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

void test_26_1()
{
    //string name, int sex, int condi
    Person *xiaofang = new Woman("小芳", 2, 5);

    Person *zhangsan = new Man("张三", 1, 4);

    Person *lisi = new Man("李四", 1, 5);
    xiaofang->getParter(zhangsan);
    xiaofang->getParter(lisi);

    SAFE_DELETE(lisi);
    SAFE_DELETE(zhangsan);
    SAFE_DELETE(xiaofang);
}
int main_26_1() {

    test_26_1();
    return 0;
}
