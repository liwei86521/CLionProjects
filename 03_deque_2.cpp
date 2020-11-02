#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/

class Person3{
public:
    Person3(string name, int score){
        this->m_Name = name;
        this->m_Socre = score;
    }

    string m_Name; //人名
    int m_Socre; //分数 平均分
};

void createPerson( vector<Person3>&v){
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5;i++){
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person3 p(name, score);

        v.push_back(p);
    }
}

void setScore(vector<Person3>&v){
    for (vector<Person3>::iterator it = v.begin(); it != v.end();it++){
        //对5个人进行打分
        deque<int>d;
        for (int i = 0; i < 10;i++){
            int score = rand() % 41 + 60; //60 ~ 100
            d.push_back(score);
        }

        //排序 从小到大
        sort(d.begin(), d.end());

        //去除 最高 和 最低
        d.pop_back(); //最高
        d.pop_front();

        int sum = 0;//总分
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
            sum += *dit;
        }

        //平均分
        int avg = sum / d.size();
        it->m_Socre = avg;
    }
}

void showSocre(vector<Person3> &v){
    for (vector<Person3>::iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名：" << it->m_Name << " 最终平均分为： " << it->m_Socre << endl;
    }
}

int main_5t() {
    //设置随机数种子
    srand((unsigned int)time(NULL));

    vector<Person3>v; //创建容器  存放 选手
    createPerson(v); //创建5名选手
    for_each(v.begin(), v.end(), [](Person3 p){
        cout << "姓名： " << p.m_Name << "   m_Socre： " << p.m_Socre << endl;
    });

    setScore(v); //打分
    showSocre(v);//展示平均分

    return 0;
}
