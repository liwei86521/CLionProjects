#include <iostream>
#include <string>
#include <stdio.h>
#include "list"
using namespace std;
/*
Observer模式是行为模式之一，它的作用是当一个对象的状态发生变化时，能够自动通知其他关联对象，自动刷新对象状态。
Observer模式提供给关联对象一种同步通信的手段，使某个对象与依赖它的其他对象之间保持状态同步。
 适用于：定义对象间一种一对多的依赖关系，使得每一个对象改变状态，则所有依赖于他们的对象都会得到通知。


使用场景：定义了一种一对多的关系，让多个观察对象（公司员工）同时监听一个主题对象（秘书），
 主题对象状态发生变化时，会通知所有的观察者，使它们能够更新自己。
*/

class Secretary; // 主题对象（秘书）

class PlayserObserver {//观察者
public:
    PlayserObserver(Secretary *secretary){
        this->m_secretary = secretary;
    }
    void update(string action){
        cout << "action:" << action << endl;
        cout << "老板来了 我很害怕啊..." << endl;
    }
private:
    Secretary *m_secretary;
};

class Secretary{
public:
    Secretary(){
        m_list.clear();
    }
    void Notify(string info){
        //给所有的 观察者 发送 情报
        for ( list<PlayserObserver *>::iterator it=m_list.begin(); it!=m_list.end(); it++)
        {
            (*it)->update(info); //
        }
    }

    void setPlayserObserver(PlayserObserver *o){
        m_list.push_back(o);
    }

private:
    list<PlayserObserver *> m_list;
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

void test_27_1(){
    Secretary			*secretary = NULL;
    PlayserObserver		*po1 = NULL;
    PlayserObserver		*po2 = NULL;

    secretary = new Secretary;
    po1 = new PlayserObserver(secretary);
    po2 = new PlayserObserver(secretary);

    secretary->setPlayserObserver(po1);
    secretary->setPlayserObserver(po2);

    secretary->Notify("老板 来了") ;
    secretary->Notify("老板 走了");

    SAFE_DELETE(secretary)  ;
    SAFE_DELETE(po1)  ;
    SAFE_DELETE(po2)  ;

}

int main_27_1() {

    test_27_1();
    return 0;
}
