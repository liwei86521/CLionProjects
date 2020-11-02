#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
// 类与类的关系 *****
//依赖(虚线): 一个类是另外一个类的函数参数或者函数返回值
class Car{};
class ZhangSan{
public:
    void goWork(Car *p){

    }
    Car * fix(){

    }
};

//关联(实线) 关联 张三 有车 (一个类 是 另外一个类的成员变量)
class AdvZhangSan{
public:
    void GoWork(){
        //m_car->
    }
protected:
private:
    Car *m_car; // 一个类(Car) 是 另外一个类(AdvZhangSan)的成员变量
};


int main_class() {


    return 0;
}
