#include <iostream>
#include <string>
#include <stdio.h>
#include <functional> //内建函数对象头文件
#include <vector>
#include <algorithm>

using namespace std;

void test10_8()
{
    //template<class T> T negate<T>//取反仿函数
    negate<int>n;
    cout << n(10) << endl;

    //加法  template<class T> T plus<T>//加法仿函数
    plus<int> p;
    cout << p(1, 1) << endl;
}

//template<class T> bool greater<T>//大于
void test10_9(){
    vector<int>v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

//    sort(v.begin(), v.end(), greater<int>()); // greater 降序
    sort(v.begin(), v.end(), less<int>()); // less 降序

    //匿名函数  lambda表达式  [](){};
    for_each(v.begin(), v.end(), [](int val){ cout << val << endl; });
}


int main10_9() {
//    test10_8();
    test10_9();

    return 0;
}
