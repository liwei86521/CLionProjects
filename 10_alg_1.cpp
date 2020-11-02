#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class MyPrint{
public:
    void operator()( int num){
        cout << "num " << num << endl;
        count++;
    }
    int count = 0;
};

void MyPrint2(int num ){
    cout << "num " << num << endl;
}

void test10_1(){
    //MyPrint是一个类 ，而不是函数
    MyPrint myPrint;
    myPrint(111);
    //MyPrint2(111);

    MyPrint()(1000);
}

//函数对象超出普通函数概念，内部可以保存状态
void test10_2(){
    MyPrint myPrint;
    myPrint(111);
    myPrint(111);
    myPrint(111);
    myPrint(111);

    cout << "myPrint使用次数：" << myPrint.count << endl;
}

//函数对象作为参数
void doPrint(MyPrint print, int num){
    print(num);
}
void test10_3(){
    doPrint(MyPrint(), 20);
}

int main_101() {

//    test10_1();
//    test10_2();
    test10_3();
    return 0;
}
