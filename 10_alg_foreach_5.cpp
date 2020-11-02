#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

/*
<algorithm>是所有STL头文件中最大的一个,其中常用的功能涉及到比较，交换，查找,遍历，复制，修改，反转，排序，合并等
遍历算法 遍历容器元素
@param beg 开始迭代器
@param end 结束迭代器
@param _callback  函数回调或者函数对象
@return 函数对象
*/

void myPrint2(int v){
	cout << v << endl;
}

struct myPrint01{
    void operator()(int v){
        cout << v << endl;
    }
};

void test10_13(){
    vector<int>v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
//    for_each(v.begin(), v.end(), myPrint2); // 功能和下面的一样
    for_each(v.begin(), v.end(), myPrint01());
}

struct myPrint02{
    void operator()(int v){
        cout << v << endl;
        m_Count++;
    }
    int m_Count;
};

//2 for_each有返回值
void test10_14(){
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    myPrint02 print2 = for_each(v.begin(), v.end(), myPrint02());
    cout << print2.m_Count << endl;
}

//3 for_each可以绑定参数进行输出
struct myPrint03 :public binary_function<int,int,void>{
    void operator()(int v ,int start) const{
        cout << v  + start << endl;
    }
};

void test10_15(){
    vector<int>v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), bind2nd(myPrint03(), 10000));
}

/*
transform算法 将指定容器区间元素搬运到另一容器中
注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
@param beg1 源容器开始迭代器
@param end1 源容器结束迭代器
@param beg2 目标容器开始迭代器
@param _cakkback 回调函数或者函数对象
@return 返回目标容器迭代器
*/

class TransForm{
public:
    int operator()(int val){
        return val + 10;
    }
};
void test10_16(){
    vector<int>v; //原容器
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    vector<int>vTarget; //目标容器
    vTarget.resize(v.size());

    transform(v.begin(), v.end(), vTarget.begin(), TransForm());
    for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });
}

//transform 第二种用法 将两个容器数据相加搬运到目标容器
class TransForm2{
public:
    int operator()(int val ,int val2){
        return val + val2;
    }
};

void test10_17(){
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10;i++){
        v1.push_back(100 + i);
        v2.push_back(200 + i);
    }
    vector<int>vTarget; //目标容器
    vTarget.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), TransForm2());

    // 300 302...
    for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });

}
int main10_16() {

//    test10_13();
//    test10_14();
//    test10_15();
//    test10_16();
    test10_17();
    return 0;
}
