#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a,int b){
    return a<b;
}

void test_11_1(){
    int num[]={2,3,1,6,4,5}; // 返回容器中最小值和最大值的指针。max_element(first,end,cmp)
    cout<<"最小值是 "<<*min_element(num,num+6)<<endl; // 最小值是 1
    cout<<"最大值是 "<<*max_element(num,num+6)<<endl; // 最大值是 6

    cout<<"最小值是 "<<*min_element(num,num+6,cmp)<<endl; // 最小值是 1
    cout<<"最大值是 "<<*max_element(num,num+6,cmp)<<endl; // 最大值是 6
}

void test_11_2(){
    vector <int >v; // 调用无参构造
    // 推入 6 个值到向量中
    for(int i = 0; i < 6; i++){
        v.push_back(i);
    }

    cout<<"最小值是 "<<*min_element(v.begin(), v.end())<<endl; // 最小值是 0
    cout<<"最大值是 "<<*max_element(v.begin(), v.end())<<endl; // 最大值是 5

}

int main11_1() {

//    test_11_1();
    test_11_2();
    return 0;
}
