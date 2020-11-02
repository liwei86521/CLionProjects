#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
/**
class Singleton2{
private:
    Singleton2(){
        cout << "Singelton 构造函数执行 2" << endl;
    }

public:
    static Singleton2 *getInstance(){
        return st;
    }

    static void FreeInstance()
    {
        if (st != NULL)
        {
            delete st;
            st = NULL;
        }
    }

private:
    static Singleton2 * st;
};

//饿汉式  先new 出来
Singleton2 *Singleton2::st = new Singleton2; // 编译的时候会打印 "Singelton 构造函数执行 2" ， 故先 把这个类注释


void test_15_2(){
    Singleton2 *p1 = Singleton2::getInstance();
    Singleton2 *p2 = Singleton2::getInstance();

    if (p1 == p2){
        cout << "是同一个对象" << endl;
    }
    else{
        cout << "不是同一个对象" << endl;
    }
    Singleton2::FreeInstance();
}
*/

int main_15_2() {

//    test_15_2();
    return 0;
}
