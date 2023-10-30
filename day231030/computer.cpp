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


