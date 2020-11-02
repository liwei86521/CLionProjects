#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm> //使用系统算法的头文件

using namespace std;

/*
vector构造函数   --> vector 动态数组
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

//例子 使用第二个构造函数 我们可以...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

 3.2.4.2 vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。

3.2.4.3 vector大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

*/

void printVector( vector<int>&v){ // 使用迭代器 iterator 访问值
    for (vector<int>::iterator it = v.begin(); it != v.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test02_1(){
    vector <int >v; // 调用无参构造
    // 推入 5 个值到向量中
    for(int i = 0; i < 5; i++){
        v.push_back(i);
    }
    printVector(v);
//    for_each(v.begin(),v.end(),[](int val){cout << val << endl;}); // lambda 函数

    int arr[] = { 2, 3, 4, 1, 9 };
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int)); // 构造 vector(v.begin(), v.end())
    printVector(v1);

    vector<int>v2(v1.begin(), v1.end()); // 构造 vector(v.begin(), v.end())
    printVector(v2);

    vector<int>v3(10, 100); // 构造函数将n个elem拷贝给本身
    printVector(v3);

    //赋值使用
    vector<int>v4;
    v4.assign(v3.begin(), v3.end());
    printVector(v4);

    v4.swap(v2);
    cout << "交换后的v4 " << endl;
    printVector(v4);
    cout << "v4容器的大小" << v4.size() << endl; // v4容器的大小5

    if (v4.empty()){
        cout << "v4空" << endl;
    }
    else{
        cout << "v4不空" << endl;
    }

    v4.resize(10,-1); //第二个参数是默认值 ，默认0
    printVector(v4);

    v4.resize(3);
    printVector(v4);

}
void myPrint(int v){
    cout << v << endl;
}

void test02_2(){
    //声明容器
    vector<int> v; //声明一个容器  这个容器中存放int类型数据 对象名称v

    v.push_back(10); //向容器中加入数据
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //遍历容器中的数据
    //利用迭代器
    vector<int>::iterator itBegin = v.begin(); // itBegin指向的是v容器中的起始位置
    vector<int>::iterator itEnd = v.end(); //itEnd指向v容器中最后一个位置的下一个地址

    //while (itBegin != itEnd) // 第一种遍历方法
    //{
    //	cout << *itBegin << endl;

    //	itBegin++;
    //}

    //第二种遍历方式
    //for (vector<int>::iterator it = v.begin(); it != v.end();it++)
    //{
    //	cout << *it << endl;
    //}

    //第三种方式 利用算法
//    for_each(v.begin(), v.end(), myPrint);
    for_each(v.begin(), v.end(), [](int val){cout << val << endl;});
}

//操作自定义数据类型
class Person{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test02_3(){
    vector<Person> v;
    Person p1("刘德华", 20);
    Person p2("张学友", 32);
    Person p3("黎明", 30);
    Person p4("郭富城", 28);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //遍历
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名: " << (*it).m_Name << " 年龄：" << it->m_Age << endl;
    }
    cout << endl;
    for_each(v.begin(), v.end(), [](Person p){
        cout << "姓名: " << p.m_Name << " 年龄：" << p.m_Age << endl;
    });
}

//存放自定义数据类型的指针
void test02_4(){
    vector<Person *> v;
    Person p1("刘德华", 20);
    Person p2("张学友", 32);
    Person p3("黎明", 30);
    Person p4("郭富城", 28);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for (vector<Person*>::iterator it = v.begin(); it != v.end();it++){
        cout << "姓名： " << (*it)->m_Name << " 年龄： " << (*it)->m_Age << endl;
    }

}

int main02_1() {
    test02_1();
    test02_2();
    test02_3();
    test02_4();

    return 0;
}
