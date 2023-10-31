/*​ 电脑主要组成部件为CPU（用计算），显卡（用于显示），内存条（用于存储）
​ 将每个零件封装成抽象基类，并且提供不同的厂商生产的不同的零件，例如intel厂商和Lenovo厂商
​ 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
​ 测试时组装三台不同的电脑进行工作
————————————————
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//创建CPU基类类
class AbsCpu
{
public:
    virtual void calculate() = 0;
};

class AbsGraphicsCard{
    public:
    virtual void show() = 0;
};

class  Absmemorybank{
    public:
    virtual void storage() = 0;
};

//Intel厂商类
//CPU
class IntelCpu:public AbsCpu{
    public:
    void calculate(){cout<<"Intel Cpu is Calculating"<< endl;}; 
};
//Graphicscard
class IntelGraphicscard:public AbsGraphicsCard{
    public:
    void show(){cout<<"Intel GraphicsCard is showing"<<endl;};
};
//memory bank
class IntelMemoryBank:public Absmemorybank{
    public:
    void  storage(){cout<<"Intel MemoryBank is working"<<endl;};
};

//Lenovo厂商类
//Cpu
class LenovoCpu:public AbsCpu{
    public:
    void calculate(){cout<<"LenovoCpu MemoryBank is working"<<endl;};
};
//GraphicsCard
class LenovoGraphicsCard :public AbsGraphicsCard{
    public:
    void show(){cout<<"Lenovo GraphicsCard is showing"<<endl;
    }
};

//Memory bank
class LenovoMemoryBank :public Absmemorybank{
    public:
    void storage(){cout<<"Lenovo MemoryBank is working"<<endl;};
};
//电脑类
class Computer{
    public:
    Computer(string *desc,AbsCpu *Cpu,AbsGraphicsCard *Gcard,Absmemorybank *Abank):m_desc(desc),m_Cpu(Cpu),m_Gcard(Gcard),m_Mbank(Abank){}
    ~Computer()
    {
        
        if(m_desc != NULL){delete m_desc;m_desc = NULL;}
        if(m_Cpu != NULL){ delete m_Cpu;m_Cpu = NULL;}
        if(m_Gcard !=NULL){ delete m_Gcard;m_Gcard = NULL;}
        if(m_Mbank != NULL){delete m_Mbank;m_Mbank = NULL; }
    }

    //制作流程
    void Makeup()
    {
        cout<<setw(25)<<setfill("*")<<"开始组装"<<*m_desc<<setw(15)<<""<<endl;
        m_Cpu->calculate();
        m_Gcard->show();
        m_Mbank->storage();
         cout<<setw(30)<<setfill("*")<<"组装完成"<<*m_desc<<setw(20)<<""<<endl;
    }

    private:
    string *m_desc;
    AbsCpu *m_Cpu;
    AbsGraphicsCard *m_Gcard;
    Absmemorybank *m_Mbank;
};

void MakeComputer()
{
    //第一台电脑的零件
    AbsCpu* IntelCpu = new IntelCpu;
    AbsGraphicsCard* IntelGraphicscard = new IntelGraphicscard;
    Absmemorybank* IntelMemoryBank = new IntelMemoryBank;

    //创建第一台电脑
    string* Computer_name1 = new strint("Intel电脑");
    Computer* Computer1 = new Computer1(Computer1,IntelCpu,IntelGraphicscard,IntelMemoryBank);
    Computer1->Makeup();
    delete Computer1;

    //第一台电脑的零件
    AbsCpu* IntelCpu = new LenovoCpu;
    AbsGraphicsCard* LenovoGraphicsCard = new LenovoGraphicsCard;
    Absmemorybank* LenovoMemoryBank = new LenovoMemoryBank;

    //创建第二台电脑
    string* Computer_name2 = new string("Lenovo电脑");
    Computer* Computer2 = new Computer2(Computer2,LenovoCpu,LenovoGraphicsCard,LenovoMemoryBank);


}

