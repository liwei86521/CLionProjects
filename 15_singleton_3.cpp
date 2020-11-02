#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
/**
static CCriticalSection cs; MFC 下演示处理 懒汉式 线程问题

class Singleton
{
private:
    Singleton()
    {
        m_count ++;
        TRACE("Singleton begin\n");
        Sleep(1000);
        TRACE("Singleton end\n");

    }
    Singleton(const Singleton &);
    Singleton& operator = (const Singleton &);

public:
    static void printV()
    {
        TRACE("printV..m_count:%d \n", m_count);
    }
    static Singleton *Instantialize()
    {
        if(pInstance == NULL)  //double check
        {
            //cs.Lock(); //只有当pInstance等于null时，才开始使用枷锁机制 二次检查
            if(pInstance == NULL)
            {
                pInstance = new Singleton();
            }
            //cs.Unlock();
        }
        return pInstance;
    }
    static Singleton *pInstance;
    static int m_count;

};

Singleton* Singleton::pInstance = 0;
int Singleton::m_count = 0;

 */