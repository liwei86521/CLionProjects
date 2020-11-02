#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
宝钢和武钢合并成立宝武，这两家公司肯定需要有多个系统需要融合，在这里我们使用宝钢的系统，武钢的系统需要进行适配，
 我们简单抽象出宝钢系统类和武钢系统类。
 适配器类（CAdapter），武钢系统的类（CWuSteelSystem），宝钢系统的类(CBaoSteelSystem)
*/

class CBaoSteelSystem{
public:
    virtual void AddPerson()=0; // 纯虚函数
};

class CWuSteelSystem{
public:
    long AddEmployee(){
        cout << "add WuSteel Employee";
        return 0;
    }
};

// 适配器类
class CAdapter: public CBaoSteelSystem{
public:
    CAdapter(CWuSteelSystem *pSystem):m_pSystem(pSystem){}

    void AddPerson(){ // 重写父类方法
        m_pSystem->AddEmployee();
    }

private:
    CWuSteelSystem *m_pSystem;
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}   // 定义宏函数
// 客户端调用的类
void test_21_3(){
    CWuSteelSystem* pSystem = new CWuSteelSystem;
    CBaoSteelSystem *pAdapter = new CAdapter(pSystem);
//    CAdapter *pAdapter = new CAdapter(pSystem);// 推荐上面的
    pAdapter->AddPerson();

    SAFE_DELETE(pAdapter) // 删除指针内存
    SAFE_DELETE(pAdapter)
}

int main_21_3() {
    test_21_3();

    return 0;
}
