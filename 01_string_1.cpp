#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

// Char*是一个指针，String是一个类
/*
string 构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化

string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串

*/

void test01_1(){
    string str; //默认构造
    string str2(str); //拷贝构造
    string str3 = str;

    string str4 = "abcd";
    string str5(10, 'a');

    cout << str4 << endl; // abcd
    cout << str5 << endl; // aaaaaaaaaa

    //基本赋值
    str = "hello";
    str2 = str4;

    //string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
    str3.assign("abcdef", 4);
    cout << str3 << endl;  // abcd


    //string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
    string str6;
    str6.assign(str, 1, 3); //ell ? hel 从0索引
    cout << str6 << endl; // ell
}

/*
string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/
void test01_2(){
    string s = "hello world";

    for (int i = 0; i < s.size();i++){
        //cout << s[i] << endl;
        cout << s.at(i) << endl;
    }
    //[] 和at区别？[]访问越界  直接挂掉 at会抛出异常

    try{
        //cout << s[100] << endl;
        cout << s.at(100) << endl;
    }
    catch (out_of_range & e){
        cout << e.what() << endl;
    }
    catch (...){
        cout << "越界异常" << endl;
    }
}

/*
string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
*/

void test01_3(){
    //拼接
    string s1 = "我";
    string s2 = "爱北京";
    s1 += s2;
    cout << s1 << endl; // 我爱北京

    s1.append("天安门"); // 我爱北京天安门
    cout << s1 << endl;

    //find查找
    string s = "abcdefg";
    int pos = s.find("bcf"); //找不到返回是 -1
    cout << "pos = " << pos << endl; // pos = -1

    int pos2 = s.rfind("bc"); //rfind  和find 结果一样，内部查找顺序相反
    cout << "pos2 = " << pos2 << endl; // pos2 = 1

    //替换
    string s3 = "hello"; //替换从pos开始n个字符为字符串str
    s3.replace(1, 3, "2222");
    cout << s3 << endl; // h1111o

    string s4 = "hello world";
    s4.replace(6,1, "kkk");
    cout << s4 << endl; // hello kkkorld
}

int main01_1() {
    test01_1();
    test01_2();
    test01_3();

    return 0;
}
