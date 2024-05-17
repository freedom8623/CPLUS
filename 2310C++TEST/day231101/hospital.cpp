#include <iostream>
using namespace std;

//创建病人类
class Patient
{
    public:
    virtual string getName() = 0;
};
//创建面诊方法
class Disposer{
    public:
    virtual void dispose(Patient *Patient) = 0;

};

//挂号
class Registry:public Disposer{//挂号，公共继承
    public:
    void dispose(Patient *Patient){
        cout << "Im registering......"<<Patient->getName()<<endl;
    }

};
//创建医生门诊
class Doctor:public Disposer{//公共继承处理方法
    public:
        void dispose(Patient *Patient){
            cout << "Im diagnosing....."<<Patient->getName()<<endl;
        }

};

//取药
class Pharmacy:public Disposer{
    public:
    void dispose(Patient *Patient)
    {
        cout << "I grab medicine..."<<Patient->getName()<<endl;
    }
};


//创建面诊
class Facade{
    private:
        Patient *patient;
    public:
        Facade (Patient *patient) {
            this -> patient = patient;
        }
    void dispose()
    {
        Registry *registry = new Registry();
        Doctor *doctor = new Doctor();
        Pharmacy *pharmacy = new Pharmacy();

        registry -> dispose(patient);
        doctor -> dispose(patient);
        pharmacy -> dispose(patient);

    }
};
//具体病人
class ConcretePatient :public Patient{
    private:
        string name;
    public:
        ConcretePatient(string name){ this -> name = name;}
        string getName(){return name;}
    
};
int main(){
    Patient *Patient =new ConcretePatient("john");//创建一个病人，病人获取自己的名字；
    Facade *f = new Facade(Patient);
    f->dispose();
}

