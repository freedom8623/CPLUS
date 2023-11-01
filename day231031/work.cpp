//设计一个可以求最大公约数的类、
#include <iostream>
using namespace std;

class Fract{
    public:
    Fract(int a = 0,int b = 1){};//构造函数，用a、b分别初始化num，分母Den
    int ged(int m ,int n){};//求m、n 最大公约数，给add（）函数调用
    Fract add(Fract f){};
    void show();//按照num/den的形式显示


    private:
    int num,den;
};

int Fract::ged(int m,int n)
{
    int k;
    if(m>n) k=n;
        else k = m;//找出m/n最小的那一个
    //依次递减找出可以整除m/n的数
    for(;k>0;k--)
        {
            if(m%k==0&&n%k == 0)
                break;
                return k;        

            
        }
}


