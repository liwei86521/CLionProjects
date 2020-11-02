#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/*****原系统A：Target*****/
class MangeSystemA{
public:
     virtual void getName(){ // 定义为 抽象接口
        cout << "获取系统A中员工的名称" << endl;
    }
};

/*****要集成的系统B：Adaptee*****/
class MangeSystemB{
public:
    void getPeopleName(){
        cout << "获取系统B中员工的名称" << endl;
    }
};

/***适配器：Adapter***/
class AdapterSystem : public MangeSystemA{ // 实现在系统A 这边获取 系统B 的信息
public:
    AdapterSystem(MangeSystemB *pSysB) :m_pSysB(pSysB){}

    void getName(){ // 重写父类的 getName 方法
        m_pSysB->getPeopleName();
    }
private:
    MangeSystemB *m_pSysB;
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

/****系统A工作场景****/
void test_21_2(){
    MangeSystemB *sysB = new MangeSystemB;
    //创建适配器
    MangeSystemA *sysA = new AdapterSystem(sysB);
    sysA->getName();

    SAFE_DELETE(sysA);
    SAFE_DELETE(sysB);

}

//优点：可以将不符合要求的接口转换为需要的接口。
//缺点：凭空多了一个适配类。

int main21_2() {

    test_21_2();
    return 0;
}
