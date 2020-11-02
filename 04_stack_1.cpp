#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
using namespace std;

/*
stack构造函数
stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
stack(const stack &stk);//拷贝构造函数

3.4.3.2 stack赋值操作
stack& operator=(const stack &stk);//重载等号操作符
3.4.3.3 stack数据存取操作
push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
3.4.3.4 stack大小操作
empty();//判断堆栈是否为空
size();//返回堆栈的大小
*/

void test04_1(){

    stack<int>s;

    s.push(10); //放入数据 push
    s.push(30);
    s.push(20);
    s.push(40);

    while (s.size() != 0){
        cout << "栈顶为 " << s.top() << endl;  //40  20  30  10
        s.pop(); //弹出栈顶元素
    }
    cout << "size = " << s.size() << endl;
}


int main_04_1() {
    test04_1();

    return 0;
}
