#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

/**
Prototype模式是一种对象创建型模式，它采取复制原型对象的方法来创建对象的实例。使用Prototype模式创建的实例，具有与原型一样的数据。
 一个复杂对象，具有自我复制功能，统一一套接口。
 * */

class Person{
public:
    virtual Person* clone() = 0;
    virtual void printT() = 0;
};

class  CPlusPlusProgrammer : public Person{
public:
    CPlusPlusProgrammer(){
        m_name = "";
        m_age = 0;
        m_resume = NULL;
        setResume("aaaa"); // 单独对指针 进行深拷贝处理
    }

    CPlusPlusProgrammer(string name, int age){
        m_name = name;
        m_age = age;
        m_resume = NULL;
        setResume("aaaa");
    }

    void setResume(char *p){
        if (m_resume != NULL){
            delete m_resume;
        }
        m_resume = new char[strlen(p) + 1];
        strcpy(m_resume, p);
    }

    virtual void printT(){
        cout << "m_name: " << m_name << " m_age: " << m_age << " m_resume: " << m_resume <<  endl;
    }
    virtual Person* clone(){
        CPlusPlusProgrammer *tmp = new CPlusPlusProgrammer;
        //tmp->m_name = this->m_name;
        *tmp = *this; // 浅拷贝， 当遇到指针时要单独处理 如 m_resume
        return tmp;
    }
private:
    string	m_name;
    int		m_age ;
    char	*m_resume;

};

void test_18(){
    Person *c1 = new CPlusPlusProgrammer("lee", 32);
    c1->printT();

    Person *c2 = c1->clone(); //对象具有自我复制功能 注意深拷贝和浅拷贝问题
    c2->printT();

    cout<<"hello..."<<endl;
}

int main_18() {

    test_18();
    return 0;
}
