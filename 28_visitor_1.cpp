#include <iostream>
#include <string>
#include <stdio.h>
#include "list"
using namespace std;

/*
Visitor模式也叫访问者模式，是行为模式之一，它分离对象的数据和行为，使用Visitor模式，
 可以不修改已有类的情况下，增加新的操作角色和职责。

 把数据结构 和 作用于数据结构上的操作 进行解耦合;
适用于数据结构比较稳定的场合

*/

class ParkElement;

class Visitor{
public:
    virtual void visit(ParkElement *parkelement) = 0;
};

class ParkElement{
public:
    virtual void accept(Visitor *visit) = 0;
};

class  ParkA : public ParkElement{
public:
    virtual void accept(Visitor *v){
        v->visit(this); //公园接受访问者访问 让访问者做操作
    }
};

class  ParkB : public ParkElement{
public:
    virtual void accept(Visitor *v){
        v->visit(this); //公园接受访问者访问 让访问者做操作
    }
};

//整个公园
class Park : public ParkElement{
public:
    Park(){
        m_list.clear();
    }
    void setParkElement(ParkElement *pe){
        m_list.push_back(pe);
    }

public:
    virtual void accept(Visitor *v){
        //v->visit(this); //公园接受访问者访问 让访问者做操作
        for (list<ParkElement *>::iterator it = m_list.begin(); it!=m_list.end(); it++ ){
            (*it)->accept(v);  //公园A 公园B 接受 管理者v访问
        }
    }

private:
    list<ParkElement *> m_list; //公园的每一部分  //应该让公园的每一个部分 都让 管理者访问
};

class VisitorA : public Visitor{
public:
    virtual void visit(ParkElement *parkelement){
        cout << "清洁工A 完成 公园A部分的 打扫 " << endl; //parkelement->getName();
    }
};

class VisitorB : public Visitor{
public:
    virtual void visit(ParkElement *parkelement){
        cout << "清洁工B 完成 公园B部分的 打扫 " << endl; //parkelement->getName();
    }
};

class ManagerVisitor : public Visitor{
public:
    virtual void visit(ParkElement *parkelement){
        cout << "管理者 访问公园 的 各个部分 " << endl; //parkelement->getName();
    }
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

void main28_01()
{
    Visitor *vA = new  VisitorA;
    Visitor *vB = new  VisitorB;

    ParkA *parkA = new ParkA;
    ParkB *parkB = new ParkB;

    //
    parkA->accept(vA);
    parkB->accept(vB);

    SAFE_DELETE (vA);
    SAFE_DELETE (vB);
    SAFE_DELETE (parkA);
    SAFE_DELETE (parkB);
}

void main28_02()
{
    Visitor *vManager = new  ManagerVisitor ;
    Park *park = new Park;

    ParkElement *parkA = new ParkA;
    ParkElement *parkB = new ParkB;

    park->setParkElement(parkA);
    park->setParkElement(parkB);

    //整个公园 接受 管理者访问
    park->accept(vManager);

    SAFE_DELETE (parkA);
    SAFE_DELETE (parkB);
    SAFE_DELETE (park);
    SAFE_DELETE (vManager);
}

int main() {

//    main28_01();
    main28_02();
    return 0;
}
