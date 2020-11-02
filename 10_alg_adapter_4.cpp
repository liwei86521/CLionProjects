#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//函数适配器bind1st bind2nd
//现在我有这个需求 在遍历容器的时候，我希望将容器中的值全部加上100之后显示出来，怎么做？
//我们直接给函数对象绑定参数 编译阶段就会报错
//for_each(v.begin(), v.end(), bind2nd(myprint(),100));
//如果我们想使用绑定适配器,需要我们自己的函数对象继承binary_function 或者 unary_function
class MyPrint:public binary_function<int,int,void>{
public:
    void operator()(int v ,int start) const{
        cout << "v = "<< v << " start = "<< start << " v+start = "<< v  + start<< endl;
    }

};

void test10_10(){
    vector<int>v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    cout << "请输入起始值" << endl;
    int num;
    cin >> num;

    for_each(v.begin(), v.end(), bind2nd( MyPrint(),num) ); // 推荐使用
//    for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}
//总结：  bind1st和bind2nd区别?
//bind1st ： 将参数绑定为函数对象的第一个参数
//bind2nd ： 将参数绑定为函数对象的第二个参数
//bind1st bind2nd将二元函数对象转为一元函数对象

//加const修饰 operator()
class GreaterThenFive:public unary_function<int,bool>{
public:
    bool operator()(int v) const{
        return v > 5;
    }
};

//取反适配器
void test10_11(){
    //一元取反
    vector<int>v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }

    //查找大于5的数字
    //需求改为 找小于5的数字
//    vector<int>::iterator pos =  find_if(v.begin(), v.end(), not1( GreaterThenFive()));

    vector<int>::iterator pos = find_if(v.begin(), v.end(),  not1( bind2nd(greater<int>(),5) ));
    if (pos!= v.end()){
        cout << "找到小于5的数字为 " << *pos << endl;
    }
    else{
        cout << "未找到" << endl;
    }
}


//成员函数适配器
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "成员函数中：姓名： " << m_Name << " 年龄：" << m_Age << endl;
    }
    void plusAge()
    {
        this->m_Age = this->m_Age + 100;
    }

    string m_Name;
    int m_Age;
};

void MyPrintPerson( Person & p){
    cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

void test10_12() {
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 15);
    Person p3("ccc", 18);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //成员函数适配器
    // mem_fun_ref
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}


int main10_12() {

//    test10_10();
//    test10_11();
    test10_12();
    return 0;
}
