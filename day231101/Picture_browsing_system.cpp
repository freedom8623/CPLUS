/*
【说明】
现欲实现一个图像浏览系统，要求该系统能够显示 BMP、 JPEG 和 GIF 三种格式的文
件，并且能够在 Windows 和 Linux 两种操作系统上运行。系统首先将 BMP、 JPEG 和 GIF
三种格式的文件解析为像素矩阵，然后将像素矩阵显示在屏幕上。系统需具有较好的扩展性
以支持新的文件格式和操作系统。为满足上述需求并减少所需生成的子类数目，采用桥接
（Bridge）设计模式进行设计， 所得类图如下图所示
*/

#include <iostream>
#include <string>
using namespace std;
//各种格式的文件最终都被转化为像素矩阵
class Matrix
{

};
class IamageImp{
    public:
    //创建一个虚函数
    virtual void doPaint(Matrix m) = 0;
};
class WinImp:public IamageImp{
  public:
    void doPaint(Matrix m){
        /*调用window系统的绘制函数绘制图像*/
    }
};

//兼容linux系统
class LinuxImp:public IamageImp{
    public:
        void doPaint(Matrix m){
            /*调用Linux系统的绘制函数绘制图像*/
        }
};

//图像
class Image{
    public:
    void setImp(IamageImp *imp){
        this->imp = imp;/*1*/
    }
    virtual void parseFile(string fileName) = 0;

protected:
    IamageImp *imp;/*2*/

};

class BMP:public Image{
    public:
    void parseFile(string fileName){
        //解析BMP文件获得一个像素矩阵对象m
         imp -> doPaint(m);//显示像素矩阵；
    }
    private:
    Matrix m;
};

class GIF:public Image{
    //此处代码省略
};

class JPEG:public Image{
    //此处代码省略
};

int main(){
    //在windows操作系统上查看demo.bmp图像文件
    Image *image1 = new BMP();/*4*/
    IamageImp *IamageImp1 = new WinImp();/*5*/
    image1->setImp(IamageImp1);/*6*/
    image1->parseFile("demo.bmp");

    return 0;

}
