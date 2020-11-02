#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
Bridge 模式又叫做桥接模式: 它的主要特点是把抽象（abstraction）与行为实现（implementation）分离开来，
 从而可以保持各部分的独立性以及应对它们的功能扩展。
*/

// 车 安装 发动机 ；不同型号的车，安装不同型号的发动机

class Engine{
public:
    virtual void InstallEngine() = 0; // 定义引擎接口
};

class Engine4400cc: public Engine{
public:
    virtual void InstallEngine(){
        cout << "我是 4400cc 发动机 安装完毕 " << endl;
    }
};

class Engine4500cc : public Engine{
public:
    virtual void InstallEngine(){
        cout << "我是 4500cc 发动机 安装完毕 " << endl;
    }
};

class Car{  // 定义car 接口
public:
    Car(Engine *engine){
        this->m_engine = engine;
    }
    virtual void installEngine() = 0;

protected:
    Engine *m_engine;
};

class WBM5: public Car{
public:
    WBM5(Engine *engine) : Car(engine){} // 继承父类的 构造方法

    virtual void installEngine(){ // 继承父类的 m_engine 属性
        cout << "我是 lee WBM5 " << endl;
        m_engine->InstallEngine();
    }
};

class WBM6 : public Car{
public:
    WBM6(Engine *engine) : Car(engine){}

    virtual void installEngine(){
        cout << "我是 王保明 WBM6 " << endl;
        m_engine->InstallEngine();
    }
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

void test_22_2()
{
    Engine	*engine = NULL;
    Car	*wbm6 = NULL;

    engine = new Engine4400cc;
    wbm6 = new WBM6(engine);
    wbm6->installEngine();

    SAFE_DELETE(wbm6);
    SAFE_DELETE(engine);
}

int main22_2() {

    test_22_2();
    return 0;
}
