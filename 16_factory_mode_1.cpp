#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;
// 多态 是设计模式的核心   掌握！！！
class Fruit{
public:
    virtual void getFruit() = 0; // 纯虚函数
};

class Banana: public Fruit{
public:
    virtual void getFruit(){
        cout << "我是香蕉...." << endl;
    }
};

class Apple: public Fruit{
public:
    virtual void getFruit(){
        cout << "我是苹果...." << endl;
    }
};

class Factory{
public:
    Fruit *create(char *p){

        if (strcmp(p, "banana") == 0){
            return new Banana;
        }
        else if (strcmp(p, "apple") == 0){
            return new Apple;
        }
        else{
            printf("不支持\n" ) ;
            return NULL;
        }
    }
};

void test_16_1(){
    Factory *f = new Factory; // f  指针
    Fruit *fruit = NULL;

    //工厂生产 香蕉
    fruit = f->create("banana");
    fruit->getFruit();
    delete fruit;

    fruit = f->create("apple");
    fruit->getFruit();
    delete fruit;

    delete f;
}


int main16_1() {
    test_16_1();

    return 0;
}
