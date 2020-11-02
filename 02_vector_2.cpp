#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

//巧用swap收缩空间
void test02_5(){
    vector<int>v;
    for (int i = 0; i < 100000; i++){
        v.push_back(i);
    }

    cout << "v的容量" << v.capacity() << endl; // v的容量131072
    cout << "v的大小" << v.size() << endl; // v的大小100000

    v.resize(3);
    cout << "v的容量" << v.capacity() << endl; // v的容量131072
    cout << "v的大小" << v.size() << endl; // v的大小3

    //巧用swap
    vector<int>(v).swap(v); // 自己与自己交换
    cout << "v的容量" << v.capacity() << endl; // v的容量3
    cout << "v的大小" << v.size() << endl; // v的大小3
}

//reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
void test02_6(){
    vector<int>v;

    v.reserve(100000); //预留出空间

    int * p = NULL;
    int num = 0;
    for (int i = 0; i < 100000;i++){
        v.push_back(i);
        if (p!=&v[0]){ // 统计存储10万个数据要开辟多少次空间， 每开辟一次空间首地址就会变一次
            p = &v[0];
            num++;
        }
    }
    cout << num << endl; // 加上v.reserve(100000);  只用1次， 注释后要18次
    // 开辟100000数据用了多少次
}

/*
vector数据存取操作
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素

3.2.4.5 vector插入和删除操作
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
*/

void printVector2( vector<int>&v){ // 使用迭代器 iterator 访问值
    for (vector<int>::iterator it = v.begin(); it != v.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test02_7(){
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    cout << "v的front " << v.front() << endl; //返回容器中第一个数据元素
    cout << "v的back " << v.back() << endl; //返回容器中最后一个数据元素

    v.insert(v.begin(), 2 ,100); //参数1  迭代器   参数2  N个数  参数3 具体插入的内容
    printVector2(v);

    v.pop_back(); //尾删
    printVector2(v);

    v.erase(v.begin()); //删除
    printVector2(v);

    //v.erase(v.begin(), v.end());
    v.clear(); //清空所有数据
    if (v.empty() ){
        cout << "为空" << endl;
    }
}

void test02_8(){
    //逆序遍历
    vector<int>v;
    for ( int  i = 0; i < 10; i++){
        v.push_back(i);
    }

    //reverse_iterator 逆序迭代器
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend();it++){
        cout << *it << " ";
    }
    cout << endl;

    //vector迭代器是随机访问的迭代器  支持跳跃式访问
    vector<int>::iterator itBegin = v.begin();
    itBegin = itBegin + 3;
    //如果上述写法不报错，这个迭代器是随机访问迭代器


    list<int>lis;
    for (int i = 0; i < 10;i++){
        lis.push_back(i);
    }
    list<int>::iterator lIt = lis.begin();
//    lIt = lIt + 1; //不支持随机访问
    for(list<int>::iterator it2=lis.begin(); it2 != lis.end(); it2++){
        cout << *it2 << " ";
    }

}


int main02_8() {
//    test02_5();
//    test02_6();
//    test02_7();
    test02_8();
    return 0;
}
