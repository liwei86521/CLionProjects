#include <iostream>
#include <string>
#include <stdio.h>
#include <queue> // 列队

using namespace std;

/*
queue构造函数
queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue &que);//拷贝构造函数
3.5.3.2 queue存取、插入和删除操作
push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素

3.5.3.3 queue赋值操作
queue& operator=(const queue &que);//重载等号操作符
3.5.3.4 queue大小操作
empty();//判断队列是否为空
size();//返回队列的大小
*/

void test05_1(){
    queue<int>q;
    q.push(10);//往队尾添加元素
    q.push(20);
    q.push(30);
    q.push(40);

    while (!q.empty()){
        //  10 40  20 40  30  40  40  40
        cout << "队头: " << q.front() << endl;
        cout << "队尾: " << q.back() << endl;
        //弹出队头元素
        q.pop();
    }
    cout << "size : " << q.size() << endl;
}



int main05_1() {

    test05_1();
    return 0;
}
