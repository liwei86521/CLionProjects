#include <iostream>
#include <string>
#include <stdio.h>
#include "list"
using namespace std;

/*
适用于：是将一个请求封装为一个对象，从而使你可用不同的请求对客户端进行参数化；对请求排队或记录请求日志，以及支持可撤销的操作。
*/

class Doctor{
public:
    void treat_eye(){
        cout << "医生 治疗 眼科病" << endl;
    }
    void treat_nose(){
        cout << "医生 治疗 鼻科病" << endl;
    }
};

class Command{
public:
    virtual void treat() = 0;
};

class CommandTreatEye : public Command{
public:
    CommandTreatEye(Doctor *doctor){
        m_doctor = doctor;
    }
    void treat(){
        m_doctor->treat_eye();
    }
private:
    Doctor *m_doctor;
};

class CommandTreatNose : public Command{
public:
    CommandTreatNose(Doctor *doctor){
        m_doctor = doctor;
    }
    void treat(){
        m_doctor->treat_nose();
    }
private:
    Doctor *m_doctor;
};

class BeautyNurse{
public:
    BeautyNurse(Command *command){
        this->command = command;
    }
public:
    void SubmittedCase(){ //提交病例 下单命令
        command->treat();
    }
private:
    Command *command;
};

//护士长
class HeadNurse {
public:
    HeadNurse(){
        m_list.clear();
    }

public:
    void setCommand(Command *command){
        m_list.push_back(command);
    }
    void SubmittedCase(){ //提交病例 下单命令
        for (list<Command *>::iterator it=m_list.begin(); it!=m_list.end(); it++){
            (*it)->treat();
        }
    }
private:
    list<Command *> m_list;
};

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}
void main24_1(){
    //1 医生直接看病
    /*
    Doctor *doctor = new Doctor ;
    doctor->treat_eye();
    delete doctor;
    */

    //2 通过一个命令 医生通过 命令 治疗 治病
    Doctor *doctor = new Doctor ;
    Command * command = new CommandTreatEye(doctor);
    command->treat();
    SAFE_DELETE(command) ;
    SAFE_DELETE(doctor) ;
}


void main24_2(){
    //3 护士提交简历 给以上看病
    BeautyNurse		*beautynurse = NULL;
    Doctor			*doctor = NULL;
    Command			*command  = NULL;

    doctor = new Doctor ;
    command = new CommandTreatNose(doctor);
    beautynurse = new BeautyNurse(command);
    beautynurse->SubmittedCase();

    SAFE_DELETE(doctor) ;
    SAFE_DELETE(command) ;
    SAFE_DELETE(beautynurse) ;
}


//4 通过护士长 批量的下单命令
void main24_3(){
    //护士提交简历 给以上看病
    HeadNurse		*headnurse = NULL;
    Doctor			*doctor = NULL;
    Command			*command1  = NULL;
    Command			*command2  = NULL;

    doctor = new Doctor ;

    command1 = new CommandTreatEye(doctor);
    command2 = new CommandTreatNose(doctor);

    headnurse = new HeadNurse(); //new 护士长
    headnurse->setCommand(command1);
    headnurse->setCommand(command2);

    headnurse->SubmittedCase(); // 护士长 批量下单命令

    SAFE_DELETE(doctor) ;
    SAFE_DELETE(command1) ;
    SAFE_DELETE(command2) ;
    SAFE_DELETE(headnurse) ;
}

int main_24_1() {

    main24_1();
    //main24_2();
//    main24_3();
    return 0;
}
