#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterThen20{
public:
    bool operator()(int val){
        return val > 20;
    }
};

//一元谓词
void test10_5(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //查找第一个大于20的数字
    //第三个参数 函数对象  匿名对象
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
    if (pos!=v.end()){
        cout << "找到大于20的数字为：" << *pos << endl;
    }
    else{
        cout << "未找到" << endl;
    }
}

//二元谓词
class MyCompare{
public:
    bool operator()(int v1 ,int v2){
        return v1 > v2;
    }
};

bool MyCompare2(int v1, int v2){
    return v1 > v2;
}

void test10_6(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

//    sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), MyCompare2);

    //匿名函数  lambda表达式  [](){};
    for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
}

int main10_5() {

    test10_5();
    test10_6();
    return 0;
}
