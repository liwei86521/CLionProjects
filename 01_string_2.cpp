#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/*
string比较操作
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。

int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
*/
void test01_4(){
    string s1 = "abc";
    string s2 = "abcd";

    if (s1.compare(s2) == 0){
        cout << "s1 等于 s2" << endl;
    }
    else if (s1.compare(s2) == 1){
        cout << "s1 大于 s2" << endl;
    }
    else{
        cout << "s1 小于 s2" << endl;  // s1 小于 s2
    }
}

/*
string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/
void test01_5()
{
    string s1 = "abcde";

    string s2 = s1.substr(1, 3);
    cout << "s2 = " << s2 << endl; // s2 = bcd

    //需求  查找一个右键的 用户名
    string email = "zhangtao@sina.com";

    int pos = email.find("@");
    cout << "pos " << pos << endl; // pos 8

    string usrName = email.substr(0, pos);
    cout << "用户名为：" << usrName << endl; // 用户名为：zhangtao
}

/*
string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/

void test01_6(){
    string s1 = "hello";
    s1.insert(1, "222");
    cout << s1 << endl; //h222ello

    //删除 111
    s1.erase(1, 3); // hello
    cout << s1 << endl;
}


// string和c-style字符串转换
void func(string s){
    cout << s << endl;
}

void func2(const char * s){
    cout << s << endl;
}

void test01_7(){
    string s = "abc";
    //string -> const char *
    const char * p = s.c_str(); // 调用c_str函数

    func(p); //const char * 隐式类型转换为 string

    //const char * -> string
    string s2(p);
    //func2(s2); //string 不能隐式类型转换为 char *
}

void test01_8(){
    string s = "abcdefg";
    char& a = s[2];
    char& b = s[3];

    a = '1';
    b = '2';

    cout << s << endl; // ab12efg
    cout << (int*)s.c_str() << endl; // 打印地址  0x8cfce0

    s = "jjjjjjjj";
    cout << s << endl;
//    func2(s.c_str());
    cout << (int*)s.c_str() << endl;

}


//写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
void test01_9(){
    string s = "abCdEfg";

    for (int i = 0; i < s.size();i++){
        s[i] = toupper(s[i]);
        //s[i] = tolower(s[i]); //全变小写
    }

    cout << s << endl; // ABCDEFG
}
int main01_4() {
    test01_4();
    test01_5();
    test01_6();
    test01_7();
    test01_8();
    test01_9();
    return 0;
}
