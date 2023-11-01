#include <iostream>
using namespace std;
class FlyBehavior {
public : virtual void fly() = 0;
};
class SubSonicFly : public FlyBehavior {
public : void fly() { cout << "亚音速飞行！ " << endl; }
};
class SuperSonicFly : public FlyBehavior {
public : void fly() { cout << "超音速飞行！ " << endl; }
};
class TakeOffBehavior {
public : virtual void takeOff() = 0;
};
class VerticalTakeOff : public TakeOffBehavior {
public : void takeOff() { cout << "垂直起飞！ " << endl; }
};
class LongDistanceTakeOff : public TakeOffBehavior {
public : void takeOff() { cout << "长距离起飞！ " << endl; }
};
class AirCraft {
protected :
FlyBehavior *flyBehavior ;/*1*/
TakeOffBehavior *takeOffBehavior ;/*2*/
public :
void fly() {flyBehavior->fly();};/*3*/
void takeOff() { takeOffBehavior->takeOff(); };/*4*/
};
class Helicopter : public AirCraft {
public :
Helicopter() {
flyBehavior = new SubSonicFly() ;/*5*/
takeOffBehavior = new VerticalTakeOff() ;/*6*/
}
~Helicopter() {/*7*/
if (!flyBehavior) delete flyBehavior;
if (!takeOffBehavior) delete takeOffBehavior;
}
};
/*， AirCraft 为抽象类，描述了抽象的飞机，
而类 Helicopter、 AirPlane、 Fighter和 Harrier 分别描述具体的飞机种类，
方法 fly()和 takeOff()分别表示不同飞机都具有飞行特
征和起飞特征；
 类 FlyBehavior 与 TakeOffBehavior 为抽象类，分别用于表示抽象的飞行行
为与起飞行为；
类 SubSonicFly 与 SuperSonicFly 分别描述亚音速飞行和超音速飞行的行
为；
类 VerticalTakeOff 与 LongDistanceTakeOff 分别描述垂直起飞与长距离起飞的行为*/