#include <iostream>
#include <string>
#include <queue>
using namespace std;

//priority_queue <int,vector<int>,greater<int> > q; //升序队列，小顶堆
//priority_queue <int,vector<int>,less<int> >q; //降序队列，大顶堆

void test05_2(){
    priority_queue<int> a; //对于基础类型 默认是大顶堆
    //等同于 priority_queue<int, vector<int>, less<int> > a;

    // 这里一定要有空格，不然成了右移运算符
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b; // 默认是大顶堆

    for (int i = 0; i < 5; i++){
        a.push(i);
        c.push(i);
    }
    while (!a.empty()){ // 大顶堆
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;

    while (!c.empty()){ // 小顶堆
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;


    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty()){
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;

}

//规则：pair的比较，先比较第一个元素，第一个相等比较第二个
void test05_3(){
    priority_queue<pair<int, int> > pq; // 默认 大顶堆
    pair<int, int> a(6, 2);
    pair<int, int> b(3, 8);
    pair<int, int> c(3, 9);
    pair<int, int> d(3, 6);
    pair<int, int> e(1, 0);
    pq.push(a);
    pq.push(d);
    pq.push(c);
    pq.push(b);
    pq.push(e);

    while (!pq.empty()){
        cout << pq.top().first << ' ' << pq.top().second << '\n';
        pq.pop();
    }// 6  2  --> 3 9  --> 3 8  --> 3 6  --> 1 0
}

// 自定义优先级，重载默认的 < 符号
struct Node{
    int x,y;
    Node(int a=0, int b=0):
            x(a), y(b) {}
};

struct cmp{
    bool operator()(Node a, Node b){ // 大顶堆
        if(a.x == b.x)	return a.y < b.y;
        return a.x < b.x;
    }
};

// priority_queue<int, vector<int>, greater<int> > c;
void test05_4(){
    priority_queue<Node, vector<Node>, cmp>  pq; // 默认 大顶堆
    Node a(6, 2);
    Node b(3, 8);
    Node c(3, 9);
    Node d(3, 6);
    Node e(1, 0);
    pq.push(a);
    pq.push(d);
    pq.push(c);
    pq.push(b);
    pq.push(e);

    while(!pq.empty()){
        cout<<pq.top().x<<' '<<pq.top().y<<endl;
        pq.pop();
    }

}


int main05_2() {

//    test05_2();
//    test05_3();
    test05_4();
    return 0;
}
