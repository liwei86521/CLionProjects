#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

// 必须 掌握 -->  代理模式, 装饰器模式, 适配器模式, 桥接模式 这4种结构型模式必须掌握
// 是将一个类的接口转换成客户希望的另外一个接口。使得原本由于接口不兼容而不能一起工作的那些类可以一起工作

class Current18v{ // 香港是用180v
public:
     virtual void use18vCurrent(){ // 定义接口 必须要 virtual
        cout << "使用18v的交流电" << endl;
    }
};

class Current220v{
public:
    void use220vCurrent(){
        cout << "使用220v的交流电" << endl;
    }
};

// 港版ipad 和 国行 ipad 电压不一样
class Adapter: public Current18v{
public:
    Adapter(Current220v *p220v){
        m_p220v = p220v;
    }

    void use18vCurrent(){
        cout << "adapter中使用电流" << endl;
        m_p220v->use220vCurrent();
    }

private:
    Current220v * m_p220v;
};

void test_21_1()
{
    // 是将一个类的接口转换成客户希望的另外一个接口。使得原本由于接口不兼容而不能一起工作的那些类可以一起工作
    Current220v *p220v = new Current220v;
    Current18v *padapter = new Adapter(p220v); // 多态, 父类引用指向子类对象， Current18v 必须用 virtual 修饰， 子类必须重写
//    Adapter *padapter = new Adapter(p220v); // 推荐上面的方式
    padapter->use18vCurrent();

    SAFE_DELETE(p220v);
    SAFE_DELETE(padapter);
}


int main_21_1() {
    test_21_1();

    return 0;
}
