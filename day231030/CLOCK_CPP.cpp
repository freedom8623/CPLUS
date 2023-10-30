
/*重载C++的时钟.cpp*/

/*设计一个时钟类，能够记录时、分、秒，重载符号++ 每次一秒且会自动进位*/

#include <iostream>
using namespace std;

class Time{
    public:
    Time(int h,int m,int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    Time operator++();
    Time operator++(int);
    //方法：显示时间
    void ShowTime()
    {
        cout<<"当前的时间为："<< hour <<":"<<minute <<":"<<second<<endl;
    }
    private:
    int hour;
    int minute;
    int second;
};

//定义Time类中的自定义++自加输入的参数
Time Time::operator++(int n)
{
    Time tmp = *this;
    ++(*this);
    return tmp;
} 

//定义Time类中的自定义++自动六十进制
Time Time::operator++()
{
    ++second;
    if(second == 60)
    {
        second = 0;
       ++ minute;
         if(minute == 60)
            {
                 minute = 0;
                 ++hour ;
    
                    
              if(hour == 24)
                    {
                        hour = 0;
                    }
        }
    }
    return *this;

}

int main(int argc,char const *argv[])
{
    Time t(23,59,55);
    ++t;
    t.ShowTime();
    (t++).ShowTime();
    t.ShowTime();

    return 0;
}
