#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//创建对组
void test08_1(){
    //第一种
    pair<string, int> p(string("Tom"), 100);

    //取值
    cout << "姓名：" << p.first << endl;
    cout << "年龄： " << p.second << endl;

    //第二种创建
    pair<string, int> p2 = make_pair("Jerry", 200);
    cout << "姓名：" << p2.first << endl;
    cout << "年龄： " << p2.second << endl;
}

int main08_1() {

    test08_1();
    return 0;
}
