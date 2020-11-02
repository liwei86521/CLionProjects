#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
/*
Strategy模式:它对一系列的算法加以封装，为所有算法定义一个抽象的算法接口，并通过继承该抽象算法接口
 对所有的算法加以封装和实现，具体的算法选择交由客户端决定（策略）。
*/

class Strategy{
public:
    virtual void crypt() = 0;
};

//对称加密  速度快 加密大数据块文件 特点:加密密钥和解密密钥是一样的.
//非对称加密 加密速度慢 加密强度高 高安全性高 ;特点: 加密密钥和解密密钥不一样  密钥对(公钥 和 私钥)
class AES :  public Strategy{
public:
    virtual void crypt(){
        cout << "AES加密算法" << endl;
    }
};
class DES :  public Strategy{
public:
    virtual void crypt(){
        cout << "DES 加密算法" << endl;
    }
};


class Context{
public:
    void setStrategy(Strategy *strategy){
        this->strategy = strategy;
    }
    void myoperator(){
        strategy->crypt();
    }

private:
    Strategy *strategy;
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

void test_25_1(){
    /*
    //1
    DES *des = new DES;
    des->crypt();
    delete des;
    */

    Strategy *strategy = NULL;
    strategy = new AES;
    Context *context = new Context;
    context->setStrategy(strategy);
    context->myoperator();

    SAFE_DELETE(strategy)  ;
    SAFE_DELETE(context)  ;
}

int main_25_1() {
    test_25_1();

    return 0;
}
