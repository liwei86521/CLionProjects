#include <iostream>
#include <string>
#include <stdio.h>

/**
设计模式基本原则:   最终目的：高内聚，低耦合
 1)  开放封闭原则  (OCP,Open For Extension, Closed For Modification Principle)
     类的改动是通过增加代码进行的，而不是修改源代码。
 3)  依赖倒置原则 (DIP,Dependence Inversion Principle)
     依赖于抽象(接口),不要依赖具体的实现(类)，也就是针对接口编程。
 7)  迪米特法则(LOD,Law of Demeter)
     一个对象应当对其他对象尽可能少的了解，从而降低各个对象之间的耦合，提高系统的可维护性。

 设计模式 的核心是多态的应用：
        C++多态成立的三个条件:
         1 要有继承
         2 有virtual重写
         3 要有父类指针（父类引用）指向子类对象  Animal * animal = new Cat;
 */

using namespace std;

class BankWorker{ // 这样设计不符合 OCP原则
public:
    void save(){
        cout << "存款" << endl;
    }

    void moveM(){
        cout << "转账" << endl;
    }

    void jiaofei(){
        cout << "交费" << endl;
    } // 假设新增 贷款功能， 这样就要改源码(类内修改)
protected:
private:
};

void main02_01(){
    BankWorker *bw = new BankWorker ;
    bw->jiaofei();
    bw->moveM();
    bw->save();
    cout<<"hello..."<<endl;

}

// 开放封闭原则 OCP  设计
class AbBankWorker{
public:
    virtual void dothing() = 0; // 纯虚函数
};

class SaveBanker: public AbBankWorker{
public:
    virtual void dothing(){
        cout << "存款" << endl;
    }
};


class MoveBanker: public AbBankWorker{
public:
    virtual void dothing(){
        cout << "转账" << endl;
    }
};

class PayBanker: public AbBankWorker{
public:
    virtual void dothing(){
        cout << "交费" << endl;
    }
};

class LoadBanker: public AbBankWorker{ // 假设新增 贷款功能
public:
    virtual void dothing(){
        cout << "贷款" << endl;
    }
};

void main02_02(){
    AbBankWorker *bw  = NULL;
    bw = new MoveBanker;
    bw->dothing(); //有多态发生
    delete bw;

    bw = new SaveBanker;
    bw->dothing();
    delete bw;
}

//框架函数
void howDo(AbBankWorker *bw){
    bw->dothing(); //有多态发生
}

void main02_03(){
    AbBankWorker *bw  = NULL;
    bw = new MoveBanker;
    howDo(bw);
    delete bw;

    bw = new SaveBanker;
    howDo(bw);
    delete bw;

    bw = new PayBanker;
    howDo(bw);
    delete bw;

    bw = new LoadBanker;
    howDo(bw);  //可扩展  调用后来人写的代码
    delete bw;
}

int main13_o() {
//    main02_01();
//    main02_02();
    main02_03();
    return 0;
}
