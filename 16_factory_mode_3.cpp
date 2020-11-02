#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Fruit{
public:
    virtual void SayName() = 0;
};

class AbstractFactory{ // 抽象工厂 可以一下生产一个产品族（里面有很多产品组成）
public:
    virtual Fruit* CreateBanana() = 0;
    virtual Fruit* CreateApple() = 0;
};

class NorthBanana : public Fruit{
public:
    virtual void SayName(){
        cout << "我是北方香蕉" << endl;
    }
};

class NorthApple : public Fruit{
public:
    virtual void SayName(){
        cout << "我是北方苹果" << endl;
    }
};


class SourthBanana : public Fruit{
public:
    virtual void SayName()
    {
        cout << "我是南方香蕉" << endl;
    }
};


class SourthApple : public Fruit{
public:
    virtual void SayName()
    {
        cout << "我是南方苹果" << endl;
    }
};

class NorthFacorty : public AbstractFactory{
    virtual Fruit * CreateBanana()
    {
        return new NorthBanana;
    }
    virtual Fruit * CreateApple()
    {
        return new NorthApple;
    }
};

class SourthFacorty : public AbstractFactory{
    virtual Fruit * CreateBanana()
    {
        return new SourthBanana;
    }
    virtual Fruit * CreateApple()
    {
        return new SourthApple;
    }
};


// 工厂模式只能生产一个产品。（要么香蕉、要么苹果）
// 抽象工厂可以一下生产一个产品族（里面有很多产品组成）
int main_16_3() {
    Fruit			*fruit = NULL;
    AbstractFactory *af = NULL;

    ///--------------
    af = new SourthFacorty;
    fruit = af->CreateApple();
    fruit->SayName();
    delete fruit;
    fruit = af->CreateBanana();
    fruit->SayName();
    delete fruit;

    ///------
    af = new NorthFacorty;
    fruit = af->CreateApple();
    fruit->SayName();
    delete fruit;
    fruit = af->CreateBanana();
    fruit->SayName();
    delete fruit;

    delete af;

    return 0;
}


int main_ttt() {
    main_16_3();
    return 0;

}