#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

// 依赖倒置原则 (DIP,Dependence Inversion Principle)  依赖于抽象(接口),不要依赖具体的实现(类)，也就是针对接口编程。
class  HardDisk{
public:
    virtual void work() = 0; // 纯虚函数
};

class  Memory{
public:
    virtual void work() = 0;
};

class  Cpu{
public:
    virtual void work() = 0;
};

//让 Computer框架  和 具体的厂商 进行接耦合
// 类与类的关系 *****
//依赖(虚线): 一个类是另外一个类的函数参数或者函数返回值
//关联(实线) 关联 张三 有车 (一个类 是 另外一个类的成员变量)
class Computer{ // 电脑 由 硬盘， 内存， CPU组成
public:
    Computer(HardDisk *handdisk, Memory *memory, Cpu *cpu){// 类之间 依赖关系
        m_handdisk = handdisk;
        m_memory = memory;
        m_cpu = cpu;
    }

    void work(){
        m_handdisk->work();
        m_memory->work();
        m_cpu->work();
    }
protected:
private:
    HardDisk *m_handdisk; //类之间  关联关系
    Memory *m_memory;
    Cpu *m_cpu;
};

class InterCpu: public Cpu{
public:
    void work(){
        cout << "我是iterl cpu 我工作良好" << endl;
    }
};


class XSDisk: public HardDisk{
public:
    void work(){
        cout << "我是西数硬盘 工作良好" << endl;
    }
};

class JSDMem: public Memory{
public:
    void work(){
        cout << "JSDMem 工作良好" << endl;
    }
};

void test14_1()
{
    HardDisk * harddisk = NULL;
    Memory * memory = NULL;
    Cpu * cpu = NULL;

    harddisk = new XSDisk; // 多态发生
    memory  = new JSDMem;
    cpu = new InterCpu;

    Computer *mycomputer = new Computer(harddisk ,memory,  cpu);
    mycomputer->work();

    delete mycomputer;
    delete cpu;
    delete memory;
    delete harddisk;

}

int main14_1() {
    test14_1();

    return 0;
}
