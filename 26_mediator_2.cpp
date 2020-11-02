#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
Mediator模式中，类之间的交互行为被统一放在Mediator的对象中，对象通过Mediator对象同其他对象交互，Mediator对象起着控制器的作用。
*/
class Mediator;

class Person{
public:
    Person(string name, int sex, int condi, Mediator *m){
        m_name = name;
        m_sex = sex;
        m_condi = condi;
        mediator = m;
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
    Mediator *mediator;
};

class Mediator{
public:
    void setMan(Person *man){
        pMan = man;
    }
    void setWoman(Person *woman){
        pWoman = woman;
    }

public:
    virtual void getParter(){
        if (pWoman->getSex() == pMan->getSex()){
            cout << "同性恋 之间 不能找对象 " << endl;
        }
        if (pWoman->getCondi() == pMan->getCondi() ){
            cout << pWoman->getName() << " 和 " << pMan->getName() << "绝配 " <<endl;
        }
        else{
            cout << pWoman->getName() << " 和 " << pMan->getName() << "不配 " <<endl;
        }
    }
private:
    Person	*pMan;
    Person	*pWoman; // list<Person *> m_list;
};

class Woman : public Person{
public:
    Woman(string name, int sex, int condi, Mediator *m) : Person(name, sex, condi, m){}

    virtual void getParter(Person *p){
        mediator->setMan(p);
        mediator->setWoman(this);
        mediator->getParter(); //找对象
    }
};

class Man : public Person{
public:
    Man(string name, int sex, int condi, Mediator *m) : Person(name, sex, condi, m){}

    virtual void getParter(Person *p){
        mediator->setMan(this);
        mediator->setWoman(p);
        mediator->getParter(); //找对象
    }
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

void test_26_2()
{
    //string name, int sex, int condi
    Mediator *m = new Mediator;
    Person *xiaofang = new Woman("小芳", 2, 5, m);
    Person *zhangsan = new Man("张三", 1, 4, m);
    Person *lisi = new Man("李四", 1, 5, m);

    xiaofang->getParter(zhangsan);
    xiaofang->getParter(lisi);


    SAFE_DELETE(lisi);
    SAFE_DELETE(zhangsan);
    SAFE_DELETE(xiaofang);
}

int main_26_2() {

    test_26_2();
    return 0;
}
