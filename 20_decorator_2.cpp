#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

// https://blog.csdn.net/lh844386434/article/details/17932039
// 案例分析: 假如你老婆喜欢化妆，她每天早上照镜子着镜子都化妆，化妆的时候要涂口红，画睫毛，抹香水。
// 老婆化妆的这个过程便是一个典型的装饰者模式，而口红，眼线笔，香水，显然就是装饰品。

class IWomen{ // 首先是爱照镜子的女人
public:
    virtual void lookIntoTheMirror() = 0;
};

class Wife : public IWomen{ // 然后老婆是个爱照镜子的喜欢打扮的女人（具体需要装饰对象）
public:
    void lookIntoTheMirror(){
        cout<<"镜子中的老婆: ";
    }
};

// 需要一个化妆的女人（装饰品的抽象基类）
class DecoratorWomen : public IWomen{
public:
    DecoratorWomen(IWomen* woman) :m_women(woman){}

    void lookIntoTheMirror(){
        m_women->lookIntoTheMirror();
        makeUp();
    }
    virtual void makeUp() = 0; //化妆

protected:
    IWomen* m_women;
};

// 下面是具体3种用于化妆的化妆品： 口红，睫毛膏，香水
class Lipstick : public DecoratorWomen{
public:
    Lipstick(IWomen* woman):DecoratorWomen(woman){};
    void makeUp(){
        cout<<"  有火红的嘴唇！";
    }
};

class Mascara : public DecoratorWomen{
public:
    Mascara(IWomen* woman):DecoratorWomen(woman){};
    void makeUp(){
        cout<<"  有黑黑的睫毛！";
    }
};

class Perfume : public DecoratorWomen{
public:
    Perfume(IWomen* woman):DecoratorWomen(woman){};
    void makeUp(){
        cout<<"  有香奈儿的味道！";
    }
};

// 客户端，老婆照镜子
void test_20_2(){
    IWomen* myWife = new Wife();
    DecoratorWomen* lips = new Lipstick(myWife);
    DecoratorWomen* mas = new Mascara(lips);
    DecoratorWomen* per = new Perfume(mas);

    per->lookIntoTheMirror();

    //释放各种资源...
    delete per;
    delete mas;
    delete lips;
    delete myWife;

}

int main_20_2() {
    test_20_2();

    return 0;
}
