#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

// 必须 掌握 -->  代理模式, 装饰器模式, 适配器模式, 桥接模式 这4种结构型模式必须掌握

/* 重要 要掌握
代理是指 具有与代理元（被代理的对象）具有相同的接口的类，客户端必须通过代理与被代理的目标类交互，
 而代理一般在交互的过程中（交互前后），进行某些特别的处理。

subject（抽象主题角色）： 真实主题与代理主题的共同接口。
RealSubject（真实主题角色）：定义了代理角色所代表的真实对象。
Proxy（代理主题角色）：
  含有对真实主题角色的引用，代理角色通常在将客户端调用传递给真是主题对象之前或者之后执行某些操作，而不是单纯返回真实的对象。

*/

class Subject{
public:
    virtual void sailbook() = 0;
};

class RealSubjectBook : public Subject{
public:
    virtual void sailbook(){
        cout << "卖书" << endl;
    }
};

//a中包含b类；a、b类实现协议类protocol
class dangdangProxy : public Subject{
public:
    dangdangProxy(Subject *subject){
        m_subject = subject;
    }

    virtual void sailbook(){
        dazhe(); // 加一些特殊功能
        m_subject->sailbook();
        dazhe();
    }

public:
    void dazhe(){
        cout << "双十一打折" << endl;
    }
private:
    Subject *m_subject;
};

void test_19_1(){
    Subject *s = new RealSubjectBook;
    Subject *proxy = new dangdangProxy(s);
    proxy->sailbook();
    delete s;

}

int main_19_1() {
    test_19_1();

    return 0;
}
