#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
/** 单例模式的定义是：保证一个类、只有一个实例存在，同时提供能对该实例加以访问的全局访问方法
    实现单例步骤常用步骤
     a)	构造函数私有化
     b)	提供一个全局的静态方法（全局访问点）
     c)	在类中定义一个静态指针，指向本类的变量的静态变量指针
*/

//懒汉式 只有在使用的时候，才去创建对象
class Singleton{
private:
    Singleton(){
        cout << "Singelton 构造函数执行 1" << endl;
    }

public:
    static Singleton * getInstance(){
        if (st == NULL){
            st = new Singleton;
        }
        return st;
    }

    static void FreeInstance(){
        if (st != NULL){
            delete st;
            st = NULL;
        }
    }

private:
    static Singleton * st; // 类内声明， 类外初始化
};

Singleton *Singleton::st = NULL;

void test_15(){
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();

    if (p1 == p2){
        cout << "是同一个对象" << endl;
    }
    else{
        cout << "不是同一个对象" << endl;
    }
    Singleton::FreeInstance();
}

int main_15_1() {

    test_15();
    return 0;
}
