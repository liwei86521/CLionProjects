#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/**
 Builder 模式适用于: 一个对象的构建比较复杂，将一个对象的构建(?)和对象的表示(?)进行分离

Factory模式中：
1、有一个抽象的工厂。
2、实现一个具体的工厂---汽车工厂。
3、工厂生产汽车A，得到汽车产品A。
4、工厂生产汽车B，得到汽车产品B。
这样做，实现了购买者和生产线的隔离。强调的是结果。

Builder模式:
1、引擎工厂生产引擎产品，得到汽车部件A。
2、轮胎工厂生产轮子产品，得到汽车部件B。
3、底盘工厂生产车身产品，得到汽车部件C。
4、将这些部件放到一起，形成刚好能够组装成一辆汽车的整体。
5、将这个整体送到汽车组装工厂，得到一个汽车产品。
这样做，目的是为了实现复杂对象生产线和其部件的解耦。强调的是过程 两者的区别在于：
    Factory模式不考虑对象的组装过程，而直接生成一个我想要的对象。
    Builder模式先一个个的创建对象的每一个部件，再统一组装成一个对象。
    Factory模式所解决的问题是，工厂生产产品。
    而Builder模式所解决的问题是工厂控制产品生成器组装各个部件的过程，然后从产品生成器中得到产品。
    Builder模式不是很常用。 *****
 * */

class House{
public:
    void setDoor(string door){
        this->m_door = door;
    }

    void setWall(string wall){
        this->m_wall = wall;
    }
    void setWindow(string window){
        this->m_window = window;
    }

    string getDoor( ){
        cout << m_door << endl;
        return this->m_door ;
    }

    string getWall(){
        cout << m_wall << endl;
        return this->m_wall;
    }
    string getWindow(){
        cout << m_window << endl;
        return m_window;
    }

private:
    string	m_door;
    string	m_wall;
    string	m_window;
};

class  Builder{
public:
    virtual void buildWall() = 0;
    virtual void buildDoor() = 0;
    virtual void buildWindow() = 0;
    virtual House* getHouse() = 0;
};

//公寓工程队
class  FlatBuilder : public Builder{
public:
    FlatBuilder(){
        m_house = new House;
    }
    virtual void buildWall(){
        m_house->setWall(" flat wall");
    }

    virtual void buildDoor(){
        m_house->setDoor("flat door");
    }

    virtual void buildWindow(){
        m_house->setWindow("flat window");
    }

    virtual House* getHouse(){
        return m_house;
    }
private:
    House *m_house;
};

//别墅 villa 工程队
class  VillaBuilder : public Builder{
public:
    VillaBuilder(){
        m_house = new House;
    }
    virtual void buildWall(){
        m_house->setWall(" villa wall");
    }

    virtual void buildDoor(){
        m_house->setDoor("villa door");
    }

    virtual void buildWindow(){
        m_house->setWindow("villa window");
    }

    virtual House* getHouse(){
        return m_house;
    }
private:
    House *m_house;
};

//设计师(指挥者) 负责建造逻辑
//建筑队 干具体的活
class Director{
public:
    Director( Builder * build){ // 多态
        m_build = build;
    }
    void Construct(){
        m_build->buildWall();
        m_build->buildWindow();
        m_build->buildDoor();
    }
private:
    Builder * m_build;
};

void test_17_1(){
    House		*house  = NULL;
    Builder		*builder = NULL;
    Director	*director = NULL;

    // 请一个建造别墅的工程队
    builder = new VillaBuilder; // 多态

    //设计师 指挥 工程队 干活
    director = new Director(builder);
    director->Construct();
    house  =  builder->getHouse();
    house->getWindow();
    house->getDoor();

    delete house;
    delete builder;

    //请 FlatBuilder 公寓
    builder = new FlatBuilder;
    director = new Director(builder);
    director->Construct();
    house  =  builder->getHouse();
    house->getWindow();
    house->getDoor();
    delete house;
    delete builder;

    delete director;
}

int main17_1() {

    test_17_1();
    return 0;
}
