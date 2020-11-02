#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

/*
//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过Multimap进行信息的插入 保存 显示( Multimap和map的操作类似，唯一区别multimap键值可重复)
//分部门显示员工信息 显示全部员工信息
*/
enum{ RENLI,YANFA,MEISHU }; // 通过枚举 来代表部门， 一个部门可以有多名员工 所以用 Multimap

class Worker{
public:
    string m_Name;
    int m_Money;
};

void createWorker(vector<Worker>&v ){
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5;i++){
        string name = "员工";
        name += nameSeed[i];

        int money = rand() % 10000 + 10000; // 10000~ 19999

        Worker w;
        w.m_Name = name;
        w.m_Money = money;

        v.push_back(w);
    }
}

void printVector3(vector<Worker> &v){
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++){
        cout << "姓名： " << it->m_Name << " 工资： " << it->m_Money << endl;
    }
}

void setGroup( vector<Worker>&v, multimap<int,Worker> & m ){
    for (vector<Worker>::iterator it = v.begin(); it != v.end();it++){
        //随机产生部门编号
        int departmentId = rand() % 3; // 0 1 2  对应前面的枚举
        //将员工分到 multimap容器中
        m.insert(make_pair(departmentId, *it));
    }
}

void showGroup( multimap<int,Worker>& m ){
    //人力部门显示
    cout << "人力部门员工如下：" << endl;

    multimap<int,Worker>::iterator pos = m.find(RENLI);
    int index = 0;
    int num = m.count(RENLI); // 统计人力部门的人数
    for (; pos != m.end(), index<num; pos++, index++){ // 0  A  B  1  C  2  D E
        cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Money << endl;
    }

    cout << "-------------------------" << endl;

    cout << "研发部门员工如下：" << endl;
    pos = m.find(YANFA);
    index = 0;
    num = m.count(YANFA);// 统计研发部门的人数
    for (; pos != m.end(), index < num; pos++, index++){ // 0  A  B  1  C  2  D E
        cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Money << endl;
    }

    cout << "-------------------------" << endl;

    cout << "美术部门员工如下：" << endl;
    pos = m.find(MEISHU);
    index = 0;
    num = m.count(MEISHU);
    for (; pos != m.end(), index < num; pos++, index++){ // 0  A  B  1  C  2  D E
        cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Money << endl;
    }
}

int main_case() {
    srand((unsigned int)time(NULL));

    //声明一个存放员工的容器
    vector<Worker> v;

    //创建5名员工
    createWorker(v);
    printVector3(v);

    //设置分组
    //分组的multimap容器
    multimap<int, Worker>m;
    setGroup(v,m);

    //分部门显示员工
    showGroup(m);

    return 0;
}
