#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
必须 掌握 -->  代理模式, 装饰器模式, 适配器模式, 桥接模式 这4种结构型模式必须掌握
桥接模式: 将抽象(Abstraction)与实现(Implementation)分离，使得二者可以独立地变化
https://blog.csdn.net/fanyun_01/article/details/51766505
*/

class HandsetSoft{ // 手机软件
public:
    virtual void run()=0;
};

class HandsetGame:public HandsetSoft{
public:
    void run(){
        cout<<"运行手机游戏"<<endl;
    }
};

class HandsetAddressList:public HandsetSoft{ // 手机通讯录
public:
    void run(){
        cout<<"运行手机通讯录"<<endl;
    }
};

class HandsetBrand{ // 手机品牌
public:
    void setHandsetSoft(HandsetSoft *soft){
        this->soft=soft;
    }
    virtual void run()=0;

protected:// 子类 可继承  protected 属性
    HandsetSoft *soft;
};

class HandsetBrandN:public HandsetBrand{
public:
    void run(){
        cout << "N 牌手机 ";
        soft->run();
    }
};

class HandsetBrandM:public HandsetBrand{
public:
    void run(){
        cout << "M 牌手机 ";
        soft->run();
    }
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

void test_22_1(){
    HandsetBrand *hb;
    hb=new HandsetBrandM(); // 多态

    hb->setHandsetSoft(new HandsetGame());
    hb->run();
    hb->setHandsetSoft(new HandsetAddressList());
    hb->run();

    SAFE_DELETE(hb);

    hb=new HandsetBrandN(); // 多态
    hb->setHandsetSoft(new HandsetGame());
    hb->run();
    hb->setHandsetSoft(new HandsetAddressList());
    hb->run();

    SAFE_DELETE(hb);

}

int main_22_1() {
    test_22_1();

    return 0;
}
